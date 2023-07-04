typedef struct mapNode{
    int loc_id;
    char whom;//0为无人空地
    int level;//0-3级
    int item[3];//bool 量，存在某一个道具，2为机器娃娃弃用
    char user[4];//在此地的玩家
    char ch;//显示字符
}mapnode;

static mapnode map[70];

#define ANSI_COLOR_RED     "\033[31m"
#define ANSI_COLOR_GREEN   "\033[32m"
#define ANSI_COLOR_YELLOW  "\033[33m"
#define ANSI_COLOR_BLUE    "\033[34m"
#define ANSI_COLOR_MAGENTA "\033[35m"
#define ANSI_COLOR_CYAN    "\033[36m"
#define ANSI_COLOR_RESET   "\033[0m"
#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define RESET   7


int printNode(mapnode node);
int initMap();
int printMap();