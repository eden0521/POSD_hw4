#ifndef FOLDER_H
#define FOLDER_H
#include "node.h"
#include <string>

using namespace std;

int level = 0;
string stringArray[100];

class Folder:public Node{
public:
    Folder(const char* path):Node(path)
    {
        string _nodePath(path);
        _nodeFullPath = _nodePath;
        _nodeName = _nodePath.substr(_nodePath.rfind("/")+1);
        //cout<<"nodeName "<<_nodeName<<endl;
    }

    void add(Node *node)
    {
        
        _children.push_back(node);
        //compare(_children[0]->nodePath());
        //cout<< "_children[0] is " << _children[0]->nodePath() <<endl <<endl;
        //cout<< "_children[1] is " << _children[1]->name() <<endl <<endl;
        checkMULTI ++;
        //cout << "321" <<endl;
        //cout<< "checkMULTI is " << checkMULTI <<endl <<endl;
    }
    
    int cntNodePath(string nodeName)
    {
        int cnt = 0;	//有幾個file/folder
        //cout << "cnt_s=" <<cnt<<endl<<endl;
        //cout << "37" << endl;
        //cout<<"This Name: "<<this->name()<<endl;
        for (int i = 0; i < _children.size(); i++)
        {
            //cout << "40" << endl;
            //cout << "_children.size() " << _children.size() << endl;
            if(_children[i]->name() == nodeName)
            {
                cnt++;
                //cout << "45" << endl;
                stringArray[level] = _children[i]->nodePath();
                //cout << "stringArray[" << level << "] = " << stringArray[i]  <<endl  <<endl;
                level++;               
            }
        }
        //cout << "50" << endl;
        //cout << "_children.size() " << _children.size() << endl;
        for (int i = 0; i < _children.size(); i++)
        {
            //cout << "55" << endl;
            //cout <<"_children[i]->numberOfChildren()= "<< _children[i]->numberOfChildren() <<endl;
            
            if(_children[i]->numberOfChildren() > 0)
            {
                //cout << "59" << endl;
                //cout <<"HIiiiiiHI "<< _children[i]->cntNodePath(nodeName) <<endl;
                cnt += _children[i]->cntNodePath(nodeName);
                //cout << "61" << endl;
            }
            
        }
        //cout << "64" << endl;
        //cout << "cnt_e=" <<cnt<<endl<<endl;
        return cnt;
    }
    
    string find(string nodeName)
    {
        if (checkMULTI == 0 )
        {
            return "";
        }
        else
        {
            ccnt = cntNodePath(nodeName);
            //cout << "ccnt" << ccnt << endl;
            //cout << "VV" << ccnt << endl;
            //cout <<"VV " <<_children[0]->cntNodePath(nodeName) <<endl;
            level = 0;
            if (ccnt == 0)
            ans = stringArray[0].erase(0, _nodeFullPath.length());
            else
            {
                ans = "";
                for (int i=0 ; i<ccnt ; i++){
                    tempans = stringArray[i].erase(0, _nodeFullPath.length());
                    // cout << "stringArray[" << i << "] " << 
                    if (i!=0)
                        ans += dot + tempans;
                    else
                        ans += tempans;
                    if (i != ccnt-1)
                        ans += slashN;
                }
            }
            return dot + ans;  
        }
    }
    string name()
    {
        return _nodeName;
    }

    string nodePath()
    {
        return _nodeFullPath;
    }

    int numberOfChildren() const
    {
        return _children.size();
    }

private:
    std::vector<Node *> _children;
    string dotSlash = "./";
    string slashN = "\n";
    string dot = ".";
    string _nodeName;
    string _nodeFullPath;
    string ans;
    string tempans;
    int checkMULTI = 0;
    int ccnt;
};

#endif