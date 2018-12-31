#include"dnaSequence.h"


//---------------------DnaSequence----------------------------------
void DnaSequence::init_and_allocate(const char* sequence) {

	assert(sequence);
	length = strlen(sequence);

	try {
		this->aux_dna = new Nucleotide[length];
		for (int i = 0; i < length; i++) {
			this->aux_dna[i] = sequence[i];
		}
	} catch (invalid_argument& e) {
		delete[] aux_dna;
		aux_dna = 0;
		throw;
	} catch (bad_alloc& e) {
		aux_dna = 0;
		throw;
	}
}
DnaSequence::DnaSequence(const char* dna_sequence) {
	init_and_allocate(dna_sequence);
}
DnaSequence::DnaSequence(const string& dna_sequence) {
	init_and_allocate(dna_sequence.c_str());
}
DnaSequence::DnaSequence(const DnaSequence& ds) {
	string str;
	for (int i = 0; i < ds.length; i++) {
		str += ds.aux_dna[i].getchar();
	}

	init_and_allocate(str.c_str());

}
DnaSequence& DnaSequence::operator=(const DnaSequence& ds) {
	if (this == &ds) {
		return *this;
	}
	delete[] aux_dna;
	string str;
	for (int i = 0; i < ds.length; i++) {
		str += ds.aux_dna[i].getchar();
	}

	init_and_allocate(str.c_str());

	return *this;
}

DnaSequence& DnaSequence::operator=(const char* str) {

	delete[] aux_dna;
	length = strlen(str);
	aux_dna = new Nucleotide[length];
	for (int i = 0; i < length; i++) {
		aux_dna[i] = str[i];

	}
	return *this;
}
DnaSequence& DnaSequence::operator=(const string& str) {
	*this = DnaSequence(str.c_str());
	return *this;
}

Nucleotide& DnaSequence::operator[](int ind) { //---------------should return int&---------------
	return aux_dna[ind];
}
Nucleotide DnaSequence::operator[](int ind) const {
	return aux_dna[ind];

}
DnaSequence DnaSequence::slicing(int from, int to) const {
	if (from < 0 || from > length || to < 0 || to > length || from > to) {
		throw invalid_argument("Invalid argument for method slice");
	}
	string result;
	for (int i = from; i < to; i++) {
		result += aux_dna[i].getchar();
	}
	return DnaSequence(result);
}
DnaSequence DnaSequence::pairing() const {
	string result;
	for (int i = 0; i < length; i++) {
		if (aux_dna[i].getchar() == 'T')
			result += 'A';
		else if (aux_dna[i].getchar() == 'A')
			result += 'T';
		else if (aux_dna[i].getchar() == 'G')
			result += 'C';
		else
			result += 'G';

	}
	return DnaSequence(result);
}
static DnaSequence::Interval findSubsequence(const DnaSequence& subSequence,
		const DnaSequence& sequence, int i) {
	int j;
	for (j = i; j < subSequence.getLength() + i && j < sequence.getLength();
			j++) {
		if (subSequence[j - i] != sequence[j]) {
			break;
		}
	}
	if (subSequence.getLength() == j - i) {
		return DnaSequence::Interval(i, j - 1);
	}
	return DnaSequence::Interval(-1, -1);

}
DnaSequence::Interval DnaSequence::find(const DnaSequence& subSequence) const {
	if (subSequence.getLength() > getLength()) {
		return DnaSequence::Interval(-1, -1);
	}
	int i;
	for (i = 0; i < getLength(); i++) {
		DnaSequence::Interval interv = findSubsequence(subSequence, *this, i);
		if (interv.getFrom() != -1) {
			return interv;
		}
	}
	return DnaSequence::Interval(-1, -1);
}
int DnaSequence::count(const DnaSequence& subSequence) const {
	int count = 0;

	if (subSequence.getLength() > getLength()) {
		return count;
	}
	int i;
	for (i = 0; i < getLength(); i++) {

		DnaSequence::Interval interv = findSubsequence(subSequence, *this, i);
		if (interv.getFrom() != -1) {
			count++;
		}
	}
	return count;
}
const vector<DnaSequence::Interval> DnaSequence::findAll(
		const DnaSequence& subSequence) const {
	vector<DnaSequence::Interval> SubsequenceIntervals;
	DnaSequence::Interval interv(0, -1);
	DnaSequence tmp = *this;
	int location = 0;
	while (true) {

		interv = tmp.find(subSequence);

		if (interv.getFrom() == -1) {
			return SubsequenceIntervals;
		} else {

			SubsequenceIntervals.push_back(
					Interval(interv.getFrom() + location,
							interv.getTo() + location));
			location += interv.getFrom() + 1;

		}
		tmp = tmp.slicing(interv.getFrom() + 1, tmp.getLength());
	}
}

static void findConsensuses(const DnaSequence& dna_sequence,
		const vector<DnaSequence::Interval>& first,
		const vector<DnaSequence::Interval>& end,
		vector<DnaSequence::Interval>& result) {
	for (int i = 0; i < (int) first.size(); i++) {
		for (int j = 0; j < (int) end.size(); j++) {
			if ((end[j].getFrom() - first[i].getTo() - 1) % 3 == 0) {
				result.push_back(
						DnaSequence::Interval(first[i].getFrom(),
								end[j].getTo()));
			}
		}
	}
}
vector<DnaSequence::Interval> DnaSequence::findAllConsensus() const {
	vector<DnaSequence::Interval> result;

	vector<Interval> first = findAll("ATG");
	vector<Interval> end1 = findAll("TAG");
	vector<Interval> end2 = findAll("TAA");
	vector<Interval> end3 = findAll("TGA");
	findConsensuses(*this, first, end1, result);
	findConsensuses(*this, first, end2, result);
	findConsensuses(*this, first, end3, result);
	return result;
}

DnaSequence::~DnaSequence() {
	delete[] aux_dna;
}

bool operator==(const DnaSequence& ds1, const DnaSequence& ds2) {

	if (ds1.length != ds2.length) {
		return false;
	}
	for (int i = 0; i < ds1.length; i++) {
		if (ds1.aux_dna[i] != ds2.aux_dna[i]) {
			return false;
		}
	}
	return true;
}
bool operator!=(const DnaSequence& ds1, const DnaSequence& ds2) {
	return !(ds1 == ds2);
}
ostream& operator<<(ostream& out, const DnaSequence& ds) {
	for (int i = 0; i < ds.length; i++) {
		out << ds.aux_dna[i];
	}

	return out;
}







