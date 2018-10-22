#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>

using namespace std;

class Node
{
public:
    Node(const char * path): _path(path)
    {
        
        lstat(_path, &_st);
        string _nodePath(_path);
        _nodeFullPath = _nodePath;
        _nodeName = _nodePath.substr(_nodePath.rfind("/")+1);
    }

    virtual string name()
    {
        return _nodeName;
    }

    virtual string nodePath()
    {
        return _nodeFullPath;
    }

    virtual int cntNodePath(string nodeName)
    {
        return 1;
    }

    virtual string find(string nodeName)
    {
        if (_nodeName.compare(nodeName) == 0)
            return _nodeName;
        else
            return "";
    }

    virtual void add(Node *node)
    {
        cout << "123" << endl;
        throw std::string("unable to add");
    }

    virtual int numberOfChildren() const
    {
        return 0;
        throw std::string("number of children: not applicable");
    }
    
    int size() const
    {
        return _st.st_size;
    }
    
private:
    const char * _path;
    struct stat _st;
    string _nodeName;
    string _nodeFullPath;
};

#endif
