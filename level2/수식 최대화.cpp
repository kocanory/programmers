#include <string>
#include <vector>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<string> priority = {"+-*","+*-", "-*+", "-+*", "*+-", "*-+"};
    vector<char> op;
    vector<long long> operand;
    int start = 0;
    for(int i = 0;i < expression.size();i++){
        if(!isdigit(expression[i])){
            op.push_back(expression[i]);
            operand.push_back(stoll(expression.substr(start, i - start)));
            start = i + 1;
        }
    }
    
    operand.push_back(stoll(expression.substr(start, expression.size() - start)));
    
    for(auto p : priority){
        vector<char> op_tmp = op;
        vector<long long> operand_tmp = operand;
        for(auto t : p){
            for(int i = 0;i < op_tmp.size();){
                if(t == op_tmp[i]){
                    if (t == '*')
                        operand_tmp[i] *= operand_tmp[i + 1];
                    if (t == '+')
                        operand_tmp[i] += operand_tmp[i + 1];
                    if (t == '-')
                        operand_tmp[i] -= operand_tmp[i + 1];
                    op_tmp.erase(op_tmp.begin() + i);
                    operand_tmp.erase(operand_tmp.begin() + i + 1);
                }
                else i++;
            }
        }
        answer = max(answer, abs(operand_tmp[0]));
    }
    
    return answer;
}