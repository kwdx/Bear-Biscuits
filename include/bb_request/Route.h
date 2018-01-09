#include <vector>
#include <map>
using namespace std;

class Route
{
    public:
        // 注册路由
        static int connect(
            string rule, map<string, string> match, vector<string> method
            /*vector<string> method, string controller, string action*/
        );
        // 匹配路由(注意优先顺序)
        static int match(vector<string> path);
};