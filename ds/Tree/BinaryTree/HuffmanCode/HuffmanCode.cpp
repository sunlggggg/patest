//
// Created by sunlggggg on 2017/8/8.
//

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct Ch {
    Ch(char ch, int wei) : ch(ch), wei(wei), code("") {};
    char ch;
    int wei;
    string code;

    //sort2
//    bool operator < ( const Ch &m)const {
//        return wei< m.wei;
//    }

};

struct Node {
    Node(Ch ch) : ch(ch), lChild(NULL), rChild(NULL) {}

    Ch ch;
    struct Node *lChild;
    struct Node *rChild;
};

bool CompareRules(Node *_X, Node *_Y) // 回调函数
{
    if (_X->ch.wei > _Y->ch.wei) // big to small
    {
        return true;
    }
}


//sort1
bool sort_by_wei(const Node v1, const Node v2) {
    return v1.ch.wei < v2.ch.wei;//升序排列
}

class HuffmanTree {
private:
    Node *Root;
    vector<Ch> vet_chs;
public:
    HuffmanTree() {
        Root = NULL;
    }

    HuffmanTree(vector<Ch> vet_chs) {
        Root = NULL;
        this->vet_chs = vet_chs;
    }

    void build() {
        list<Node> list_chs_help;
        vector<Ch>::iterator iter_vet_chs_iter = this->vet_chs.begin();
        while (iter_vet_chs_iter != this->vet_chs.end()) {
            Node node = Node(*iter_vet_chs_iter);
            list_chs_help.push_back(node);
            iter_vet_chs_iter++;
        }
        //sort1
        // Sort(list_chs_help.begin(), list_chs_help.end(), sort_by_wei);
        //sort2
        // Sort(this->vet_chs.begin(), this->vet_chs.end(), greater<Node *>());
        list_chs_help.sort(CompareRules);
        while (list_chs_help.size() > 1) {
            int sum_wei = list_chs_help.front().ch.wei + (*++list_chs_help.begin()).ch.wei;
            Ch ch = Ch(' ', sum_wei);
            Node node = Node(ch);
            list_chs_help.pop_front();
            list_chs_help.pop_front();
            list_chs_help.push_front(node);
            //Sort(list_chs_help.begin(), list_chs_help.end(), sort_by_wei);
            if (this->Root != NULL) {

            }
        }
    }

};


int main() {
    vector<Ch> ve_chs;
    ve_chs.push_back(Ch('A', 8));
    ve_chs.push_back(Ch('B', 1));
    ve_chs.push_back(Ch('C', 2));
    ve_chs.push_back(Ch('D', 5));
    ve_chs.push_back(Ch('E', 12));
    ve_chs.push_back(Ch('F', 2));
    HuffmanTree huffmanTree(ve_chs);
    huffmanTree.build();
    //todo
    return 0;
}