/**
 *                             _ooOoo_
 *                            o8888888o
 *                            88" . "88
 *                            (| -_- |)
 *                            O\  =  /O
 *                         ____/`---'\____
 *                       .'  \\|     |//  `.
 *                      /  \\|||  :  |||//  \
 *                     /  _||||| -:- |||||-  \
 *                     |   | \\\  -  /// |   |
 *                     | \_|  ''\---/''  |   |
 *                     \  .-\__  `-`  ___/-. /
 *                   ___`. .'  /--.--\  `. . __
 *                ."" '<  `.___\_<|>_/___.'  >'"".
 *               | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *               \  \ `-.   \_ __\ /__ _/   .-` /  /
 *          ======`-.____`-.___\_____/___.-`____.-'======
 *                             `=---='
 *          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 *                     佛祖保佑        永无BUG
 */

/**
 * @file   ExamYou.c
 * @brief Just a boring program.
 *
 *  This program has been made for generate some questions that used to test the level in arithmetic of primary school students.
 *
 * @author James(chenpengsmail@qq.com)
 * @date   2016-07-04
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_EN_LEN (2)           /**< Indicate how long alphabet does the ID have.*/
#define ID_NUM_LEN (4)          /**< Indicate how long number string does the ID have.*/
#define ID_LEN (ID_EN_LEN+ID_NUM_LEN) /**< Indicate totally length of ID*/
#define MAX_TITLE_LEN (256)
#define MAX_STEM_LEN (256)
#define QUESTION_NUM (10)

static char ID[ID_LEN + 1];

typedef enum { false, true } bool;
typedef void (*MenuItemFun)();

#define MakeMenuItem(c,title,fun) { fun,c,title }
#define MenuItemNULL MakeMenuItem('\0',"",(MenuItemFun)NULL)

typedef struct {
    MenuItemFun fun;
    char c;
    char title[MAX_TITLE_LEN];
} MenuItem;

void MenuFunExit() {
    printf("Bye.%s\n",ID);
    exit(0);
}

typedef struct {
    char stem[MAX_TITLE_LEN];
    int correctAnswer;
    int youAnswer;
} Question;

Question questionList[QUESTION_NUM];

/**
 * Check if the character is uppercase.
 *
 * @param c Which character will be checked.
 * @return if c is uppercase return true,otherwise return false.
 */
static inline bool checkUppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

/**
 * Check if the character is number.
 *
 * @param c Which character will be checked.
 * @return if c is number return true,otherwise return false.
 */
static inline bool checkNum(char c) {
    return c >= '0' && c <= '9';
}

/**
 * Check if the ID is valid.
 *
 * @param id Which string will be checked.
 * @return if id is valid return true,otherwise return false.
 */
static inline bool checkID(const char *id) {
    int index = 0;
    bool pass = true;
    int i = 0;
    for (i = 0; i < ID_EN_LEN; ++i) {
        pass = pass && checkUppercase(id[index++]);
        if (!pass) return pass;
    }
    for (i = 0;i < ID_NUM_LEN; ++i) {
        pass = pass && checkNum(id[index++]);
        if (!pass) return pass;
    }
    return pass;
}

typedef int (*OperatorFun)(int a,int b);

typedef struct {
    char operator;
    OperatorFun fun;
} QuestionMaker;

static inline void MakeQuestion(Question *question) {
    
}

void MenuFunStartTest() {
    int i = 0;
    for (i = 0; i < QUESTION_NUM; i++) {
        MakeQuestion(&questionList[i]);
        printf("%s = ",questionList[i].stem);
        scanf("%d",&questionList[i].youAnswer);
        printf("\n");
    }
}

void MenuFunCheckScore() {
    
}

void PrintMenu(const MenuItem *itemList) {
    system("clear");
    char c[256] = {0};
    const MenuItem *pCurrent = NULL;
    for (pCurrent = itemList; pCurrent->fun != NULL; ++pCurrent) {
        printf("(%c) %s\n",pCurrent->c,pCurrent->title);
    }
    printf("*********************************\n");
    printf("Please input you choice : ");
    fflush(stdin);
    scanf("%s",c);

    for (pCurrent = itemList; pCurrent->fun != NULL; ++pCurrent) {
        if (c[0] == pCurrent->c) {
            pCurrent->fun();
        }
    }
}

int main(int argc, char *argv[]) {
    memset(ID,0,ID_LEN);
    printf("Please input you ID :");
    scanf("%s",ID);
    if (!checkID(ID)) {
        printf("YOU ARE INPUT AN *INVALID* ID !!! \nThat program will be close immediately...");
        return 0;
    }
    while(true) {
        MenuItem menuItemList[] = {
            MakeMenuItem('1',"Start test.",MenuFunStartTest),
            MakeMenuItem('2',"Check score.",MenuFunCheckScore),
            MakeMenuItem('3',"Exit.",MenuFunExit),
            MenuItemNULL };
        PrintMenu(menuItemList);
    }

    return 0;
}

