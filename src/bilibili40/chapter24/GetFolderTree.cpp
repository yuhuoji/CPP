/**
 * @date 2023-05-18
 * TODO cpp字符串
 */
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class TreeNode {
private:
public:
    string name;
    map<string, TreeNode> nextMap; // 用有序表来顺序输出
    TreeNode(){};
    TreeNode(const string name)
        : name(name){};
    ~TreeNode(){};
};
TreeNode generateFolderTree(vector<string>& folderPaths) {
    Node head("");                             // 根目录
    for (const auto& foldPath : folderPaths) { // 遍历绝对路径
        vector<std::string> paths;

        stringstream ss(foldPath); // 将字符串输入流化为 std::stringstream 对象
        string token;
        while (getline(ss, token, '\\')) {
            paths.push_back(token);
        }

        Node cur = head;
        for (int i = 0; i < paths.size(); i++) {
            if (cur.nextMap.find(paths[i]) == cur.nextMap.end()) {
                // 新建Node(paths[i])并加入nextMap

                cur.nextMap[paths[i]] = Node(paths[i]);
            }
            cur = cur.nextMap[paths[i]]; // 向下移动
        }
    }
    return head;
}
string get2nSpace(int n) {
    string res = "";
    for (int i = 1; i < n; i++) {
        // res拼接空格
        res += "  ";
    }
    return res;
}
/**
 * 深度优先
 * 当前所在层数
 */
void printProcess(Node node, int level) {
    if (level != 0) {
        cout << get2nSpace(level) << node.name << endl;
    }
    for (auto&& next : node.nextMap) {
        printProcess(next.second, level + 1);
    }
}

void print(vector<string>& folderPaths) {
    if (folderPaths.size() == 0) {
        return;
    }
    Node head = generateFolderTree(folderPaths); // 生成前缀树
    printProcess(head, 0);                       // 深度优先打印
}
int main() {
    string str = "a\\b\\c";
    cout << str << endl;
    vector<string> tokens;
    stringstream ss(str); // 将字符串输入流化为 std::stringstream 对象
    string token;
    while (getline(ss, token, '\\')) {
        tokens.push_back(token);
    }
    printf("-----\n");
    for (auto&& t : tokens) {
        cout << t << ", ";
    }
    cout << "-----" << endl;

    vector<string> folderPaths = {"a\\b\\c", "a\\b\\d", "a\\e\\f", "a\\e\\g"};

    print(folderPaths);
    return 0;
}