#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string buffOutput;
stack<string> markStack;
stack<string> lastURL;
string quoteBuff;

#define endLine '\n' 

string processMark(string mark) {
    if(mark == "h1") return "#";
    if(mark == "h2") return "##";
    if(mark == "i") return "*";
    if(mark == "b") return "__";
    if(mark == "url") return "[";
    if(mark == "img") return "![";
    return "";
}

bool quoteBuffNotOver() {
    int l = quoteBuff.length();
    if(quoteBuff[l-1]==']' && quoteBuff[l-2]=='e' && quoteBuff[l-3]=='t' 
        && quoteBuff[l-4]=='o' && quoteBuff[l-5] == 'u' && quoteBuff[l-6] == 'q'
        && quoteBuff[l-7] == '/' && quoteBuff[l-8] == '[') return false;
        else return true;
}

string trim(string str) {
    string::size_type pos = str.find_first_not_of(" \n\r\t");
    if (pos == string::npos) return str;
    string::size_type pos2 = str.find_last_not_of(" \n\r\t");
    if (pos2 != string::npos) return str.substr(pos, pos2 - pos + 1);
    return str.substr(pos);
}


int main(int argc, char* argv[]) {
    char c, lastC = endLine;
    while((c = getchar()) != EOF) {
        if(c == '[') { // 如果是个标签 
            string mark = ""; int i = 0; bool isEnd = false; char t;
            while((t = getchar()) != ']') {
                if(t == '/' && i == 0) {
                    isEnd = true;
                } else {
                    mark.push_back(t);
                    i++;
                }
            }

            if(mark == "quote") { // 处理quote 
                if(lastC != endLine) { // 不在新的一行
                    buffOutput += endLine;
                }
                quoteBuff = "";
                while(quoteBuff.length() < 8 || quoteBuffNotOver()) {
                    char t = getchar();
                    quoteBuff += t;
                }
                quoteBuff = "> " + trim(quoteBuff.substr(0, quoteBuff.length() - 8));
                for(int pos = 0; pos != quoteBuff.length(); pos++) {
                    if(quoteBuff[pos] == endLine) {
                        quoteBuff.insert(pos+1, "> ");
                    }
                }
                buffOutput += quoteBuff;
                buffOutput += endLine;
            } else if(mark[0] == 'u' || (mark[0] == 'i' && mark.length() > 1)) { // 处理url和img
                if(isEnd) {
                    if(markStack.size() == 0 || mark != markStack.top()) {
                        puts("Match Error");
                        return 0;
                    }
                    markStack.pop();
                    buffOutput += "](";
                    buffOutput += lastURL.top();
                    lastURL.pop();
                    buffOutput += ")";
                } else {
                    lastURL.push(mark.substr(4, mark.length()-4));
                    markStack.push(mark.substr(0,3));
                    buffOutput += processMark(mark.substr(0,3));
                }
            } else { // 处理其他情况
                if(isEnd) {
                    if(markStack.size() == 0 || mark != markStack.top()) {
                        puts("Match Error");
                        return 0;
                    }
                    markStack.pop();
                    if(mark[0] == 'h') buffOutput += ' ';
                    buffOutput += processMark(mark);
                } else {
                    markStack.push(mark);
                    buffOutput += processMark(mark);
                    if(mark[0] == 'h') buffOutput += ' ';
                }
            }
        } else { 
            buffOutput += c;
        }
        lastC = c;
    }

    if(markStack.size() != 0) {
        string unc = string("Uncl") + string("osed Mark");
        puts(unc.c_str());
    } else {
        puts(buffOutput.c_str());
    }
    return 0;
}
