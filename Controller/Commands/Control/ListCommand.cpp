
#include "ListCommand.h"
#include "../../DnaAnalyzer.h"


string ListCommand::execute(vector<string> &strs){
    ostringstream oss;
    vector<DnaSequenceMember>members_vec= DnaAnalyzer::getInstance()->get_all_the_sequences();

    for(vector<DnaSequenceMember>::iterator it=members_vec.begin();it!=members_vec.end();++it){
        oss << "[" << (*it).getID() << "] " << (*it).getName() << ": "
           << (*it).formated_string();
        if(it!=members_vec.end()-1){
            oss<<endl;
        }

    }

    return oss.str();
}
