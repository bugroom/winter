/*-----------------------------------
����    ��   �ַ�������С���
����    ��   404name / ����N
���ʱ�䣺   2021.1.11
˵�����������̫�ñ����濼�ǳ�һ�ڽ̳̣������Ĺ���ʮ��ǿ��
	  ���㲻�������Ը�д�������������������ҲֻҪд�����Ȼ����ҳ��ȥ���þ�����ʾ��
	 ���˸������ֻҪ 
	 ������ܣ�
	 �ᴩȫ�������һ��index �ĸ�����ǵ�n�������
	 appMap�������� ȡֵ����һ��index��������±�ȥappMapMessage�������������ľ�����Ϣ��λ��
	 ���ȥappMapIron������indexȥȡ���������ַ������ݣ���Щ�ǲ���д���ľ�Ҫ�����趨��Ҫ����ȥ��ӡ
	 
	  
	 appMap[20][12][7] : ����棬��ʾ��20��12*7�Ľ��� ������ƺ��ر���Ҫ����˵��
	 					�����Ȳ����� 
	 appMapMessage[100][5] ����ȡ����Ӧ�����ݵľ�����Ϣ 
	 appMapIcon[100][1000]������� 
	  
	��Ҫ�������� 
	printDemo(index,bool);  html��ҳ���������ƶ�����������ƿ��ĸ���ú������������״̬��
	checkAction �����Ƽ�����������·����תȫ���Ǳ����� 
	move���������ƶ� 
-----------------------------------*/

#include <conio.h>  //getch()
#include <stdio.h>
#include <windows.h>
#define Is_Active_Color 115     //��ǰ����״̬������ɫ ǳ��ɫ�ҵ�
#define Is_Selected1_Color 128  //��ѡ�е���ɫ1 ��ɫ��ҵ�
#define Is_Selected2_Color 62   //��ѡ�е���ɫ2 ��ɫ����
#define Is_Selected3_Color \
    369  //��ѡ�е���ɫ3 ����ɫ��ɫ(���һЩ�ַ�����ʾ������)
#define Video_Color 3     //��Ƶ��ɫ ��ɫ�ڵ�
#define Normal_Color 112  //��������ɫ �ҵ�
#define Boder_Color 391   //�߿����ɫ ��ҵ�
const int WIDTH = 53;     //��λ���
const int HEIGHT = 47;    //��λ�߶�
const int L = 4;          //�û�ͷ�񳤿�
const int LL = 20;        //��Ƶ���泤��
const int N = 50;         //���⡢�û����������
const int M = 1000000;    //��Ƶ�ղأ���������˿������
/*appMap������ӳ�䣬ȡ��������ֵ��Ӧ����ľ�����Ϣ
0�߽� 1��ͷ��(�����¼) 2������ 3��Ϣ
4 5 6 7 8 ֱ��/�Ƽ�/����/׷��/Ӱ��
9-14 6����Ƶ��
15-19 ��ҳ/�Ƽ�/��̬/��Ա��/�ҵ�
20 404ҳ��  */
/*ȫ�ֱ���
nowPage 0 1 2 3 404ҳ��/��ҳ/����/�ҵ�/����ҳ��/������
*/
int nowPage = 1;
bool onPlay = false;   //�ر�����ɱ��
bool stopPlay = true;  //��������ֹͣ
int activeIndexBottom = 15;  //��ǰ��Ӧ��ҳ��(����
int activeIndexTop = 5;      //��ǰ��Ӧ��ҳ��(�ײ�
char bacground[48][55] = {
    "                                                     ",
    "                                                     ",
    "              �� �� �� Ȥ �� �� Ƶ                   ",
    "                                                     ",
    "                    �� �� B վ                       ",
    "                  r.                                 ",
    "                 vPvi                                ",
    "                   Qq                                ",
    "               .iirj77JYLr:                          ",
    "             iY1Lvrirrr77Ls1i        ::::.           ",
    "            5J7r7rrirrri7iir1v    ..iui.     7M:     ",
    "           Z7rrrrir7i:rivZuiiJv.....   ..::  BBBB:   ",
    "          2PrirrrrLb7iri:vMb7i1:    .   . .:v7 vu.   ",
    "          QjisrrrduidS72uvririrv  ..   . ...2r  . :  ",
    "          QUrLri7Br  :vEi:BBbisDL ..  :    ...U:  .: ",
    "          sQu7irr2 .v.    BZrr1..   .L2.:    rB    : ",
    "          .MP:irriuQi.      :bPu::::i  :v     i   .: ",
    "           BY7v:i25:   :r:  21.B5   UBBUr .. :v  .:  ",
    "          vQEMQPjKD5i  :r.iBPr      iBR7  .  :u. .:  ",
    "         :EBBgbMZ. :vJrMB7  rj:       ...  ri.7rrr.  ",
    "       is i.    jr  . ..i   r:7Xv..  .r:..sJ5Ksv17:  ",
    "     vSu.    ir1Bb77v::ru. .    :iUBBB  UZi..: i..   ",
    ".     Yv:. 7BQBBBXq2IUqSKdi:ir   :7PB7  qE.   :. ::  ",
    ":gBBBBQgE22QQQBBii. .Rir: :s.   Prsd.. r.     .:::.  ",
    "  uBBBBQQgQQBDP:     i.r.:  ....i  :   i.       .    ",
    "    .r7YKQBRs:i.    :  BBBB2. .... u   i.            ",
    "       sBBd:ii .ii:rL. 2uUui      .r.  :S.           ",
    "       :..  .  .i:r7:r:           :v7i :ZS.          ",
    "             r... .:ii:           r:.:..  :          ",
    "           .BBB.   :. .          .        ..         ",
    "           dBjBB5bBBgKq           Ji .r   .          ",
    "               qQBBBQBB          .BB:RIidB:          ",
    "                :BBBBQB          :BQBBBBBB           ",
    "                   rBBB           1bJ BBBi           ",
    "                    BBB               BBB            ",
    "                   :BMQ               QBQ            ",
    "                    BRB7             jBBJ            ",
    "                     QMB.            BBB             ",
    "                      QRBQg2      qQBBBr             ",
    "                      .s7:.        .:7i              ",
    "                ____  _ _ _ _     _ _ _ 	   	      ",
    "               |  _ \\(_) (_) |   (_) (_)		       ",
    "               | |_) |_| |_| |__  _| |_ 		      ",
    "               |  _ <| | | | '_ \\| | | |		       ",
    "               | |_) | | | | |_) | | | |		      ",
    "               |____/|_|_|_|_.__/|_|_|_|		      ",
    "                                                     ",
};
//��ά������   �ĸ����� ��������  ĳ�еڼ���ģ��
// appMap[x][0][0]��ʾ��ҳ���м���
int appMap[20][12][7] = {{{5, 0, 0, 0, 0, 0, 0},  // 0.404����ҳ��
                          {0, 1, 2, 2, 2, 3, 0},
                          {0, 20, 20, 20, 20, 20, 0},
                          {0, 15, 16, 17, 18, 19, 0},
                          {0, 0, 0, 0, 0, 0, 0}},
                         {{8, 0, 0, 0, 0, 0, 0},  // 1.��ҳ
                          {0, 1, 2, 2, 2, 3, 0},
                          {0, 4, 5, 6, 7, 8, 0},
                          {0, 9, 9, 10, 10, 10, 0},
                          {0, 11, 11, 12, 12, 12, 0},
                          {0, 13, 13, 14, 14, 14, 0},
                          {0, 15, 16, 17, 18, 19, 0},
                          {0, 0, 0, 0, 0, 0, 0}},
                         {{10, 0, 0, 0, 0, 0, 0},  // 2.���� (������ )
                          {0, 1, 2, 2, 2, 3, 0},
                          {0, 4, 5, 6, 7, 8, 0},
                          {0, 25, 25, 26, 27, 28, 0},
                          {0, 21, 21, 21, 21, 21, 0},
                          {0, 22, 22, 22, 22, 22, 0},
                          {0, 23, 23, 23, 23, 23, 0},
                          {0, 24, 24, 24, 24, 24, 0},
                          {0, 15, 16, 17, 18, 19, 0},
                          {0, 0, 0, 0, 0, 0, 0}},
                         {{8, 0, 0, 0, 0, 0, 0},  // 3.�ҵ�(������ )
                          {0, 1, 2, 2, 2, 3, 0},
                          {0, 4, 5, 6, 7, 8, 0},
                          {0, 9, 9, 10, 10, 10, 0},
                          {0, 11, 11, 12, 12, 12, 0},
                          {0, 13, 13, 14, 14, 14, 0},
                          {0, 15, 16, 17, 18, 19, 0},
                          {0, 0, 0, 0, 0, 0, 0}},
                         {{9, 0, 0, 0, 0, 0, 0},  // 4.��Ƶ��ϸҳ(���)
                          {0, 29, 29, 29, 29, 29, 0},
                          {0, 30, 31, 32, 32, 33, 0},
                          {0, 34, 34, 34, 34, 35, 0},
                          {0, 36, 36, 36, 36, 36, 0},
                          {0, 37, 38, 39, 40, 41, 0},
                          {0, 42, 42, 42, 42, 42, 0},
                          {0, 43, 43, 43, 43, 43, 0},
                          {0, 0, 0, 0, 0, 0, 0}},
                         {{8, 0, 0, 0, 0, 0, 0},  // 5.��Ϣҳ�� (������ )
                          {0, 1, 2, 2, 2, 3, 0},
                          {0, 25, 25, 26, 27, 28, 0},
                          {0, 21, 21, 21, 21, 21, 0},
                          {0, 22, 22, 22, 22, 22, 0},
                          {0, 23, 23, 23, 23, 23, 0},
                          {0, 24, 24, 24, 24, 24, 0},
                          {0, 0, 0, 0, 0, 0, 0}}};
/*appMapȡ�������ݶ�Ӧ������±꣬
��Ϣ������ӳ�䵽ʵ�ʴ�ӡ���� x/y/��/��/���
��� 0 �޹����� �������ȥ
           1 �й����� �������action
           2 ������
*/
int appMapMessage[100][5] = {
    {0, 0, 0, 0, 0},
    {1, 2, 2, 6, 1},  // 1-3 ������Ϣ�� ͷ��/������/��Ϣ
    {1, 12, 2, 31, 1},
    {1, 43, 2, 8, 1},
    {4, 2, 1, 9, 1},   // 4-8 ������ǩ������
    {4, 12, 1, 9, 1},  //�Ƽ�
    {4, 22, 1, 9, 1},  //����
    {4, 32, 1, 9, 1},  //
    {4, 42, 1, 9, 1},
    {6, 1, 11, 25, 1},  // 9-14 6����Ƶ��λ
    {6, 27, 11, 25, 1},
    {18, 1, 11, 25, 1},
    {18, 27, 11, 25, 1},
    {30, 1, 11, 25, 1},
    {30, 27, 11, 25, 1},
    {42, 2, 4, 9, 1},  // 15-19 �ײ���ǩ������
    {42, 12, 4, 9, 1},
    {42, 22, 4, 9, 1},
    {42, 32, 4, 9, 1},
    {42, 42, 4, 9, 1},
    {6, 2, 35, 49, 0},  // 20.404ҳ��
    {10, 2, 7, 49, 1},  // 21-24. top���Ű�ҳ��
    {18, 2, 7, 49, 1},
    {26, 2, 7, 49, 1},
    {34, 2, 7, 49, 1},
    {6, 4, 4, 10, 1},  // 25-28 �м�4���������� ��Ϣ����
    {6, 16, 4, 10, 1},
    {6, 27, 4, 10, 1},
    {6, 39, 4, 10, 1},
    {1, 1, 14, 51, 1},  // 29 ��Ƶģ��
    {15, 7, 1, 4, 1},  // 30-33 ��Ƶ�·����� ���/����/���ҷ���Ļ/��Ļ����
    {15, 18, 1, 10, 1},
    {15, 32, 1, 15, 1},
    {15, 47, 1, 2, 1},
    {17, 1, 2, 40, 1},  // 34-36 ��Ƶ�·���Ϣ�� ����ҳ/��ע/��Ƶ����+���
    {17, 44, 2, 8, 1},
    {20, 1, 5, 51, 1},
    {26, 2, 4, 9, 1},  // 37-41 ����/��ϲ��/Ͷ��/�ղ�/ת��
    {26, 12, 4, 9, 1},
    {26, 22, 4, 9, 1},
    {26, 32, 4, 9, 1},
    {26, 42, 4, 9, 1},
    {31, 2, 7, 49, 1},
    {39, 2, 7, 49, 1},  // 42-45 ����ҳ��4����Ƶģ�� ���Ƽ�����
    {31, 2, 7, 49, 1},
    {39, 2, 7, 49, 1},  // 43-45��Ƶ�·���� + �Ƽ���Ƶ
};
char appMapIcon[100][1000] = {
    " ",
    "[����][ͷ��]",  // 1-5
    "|o #########################  || \\                           |",
    "����Ϣ��        ",
    "��ֱ���� ",
    "���Ƽ��� ",
    "�����š� ",  // 6-10
    "��׷���� ",
    "��Ӱ�ӡ� ",
    ".=======================."
    "|                       |"
    "|                       |"
    "|        ���޷���       |"
    "|                       |"
    "|                       |"
    "|__________________x:xx_|"
    "|�ʳ���Ǹ����Ҫ�ҵ���Ƶ |"
    "|������                 |"
    "|Up��xxxxxx          �� |"
    ".=======================.",
    ".=======================."
    "|                       |"
    "|                       |"
    "|        ���޷���       |"
    "|                       |"
    "|                       |"
    "|__________________x:xx_|"
    "|�ʳ���Ǹ����Ҫ�ҵ���Ƶ |"
    "|������                 |"
    "|Up��xxxxxx          �� |"
    ".=======================.",
    ".=======================."
    "|                       |"
    "|                       |"
    "|        ���޷���       |"
    "|                       |"
    "|                       |"
    "|__________________x:xx_|"
    "|�ʳ���Ǹ����Ҫ�ҵ���Ƶ |"
    "|������                 |"
    "|Up��xxxxxx          �� |"
    ".=======================.",  // 11-15
    ".=======================."
    "|                       |"
    "|                       |"
    "|        ���޷���       |"
    "|                       |"
    "|                       |"
    "|__________________x:xx_|"
    "|�ʳ���Ǹ����Ҫ�ҵ���Ƶ |"
    "|������                 |"
    "|Up��xxxxxx          �� |"
    ".=======================.",
    ".=======================."
    "|                       |"
    "|                       |"
    "|        ���޷���       |"
    "|                       |"
    "|                       |"
    "|__________________x:xx_|"
    "|�ʳ���Ǹ����Ҫ�ҵ���Ƶ |"
    "|������                 |"
    "|Up��xxxxxx          �� |"
    ".=======================.",
    ".=======================."
    "|                       |"
    "|                       |"
    "|        ���޷���       |"
    "|                       |"
    "|                       |"
    "|__________________x:xx_|"
    "|�ʳ���Ǹ����Ҫ�ҵ���Ƶ |"
    "|������                 |"
    "|Up��xxxxxx          �� |"
    ".=======================.",
    "  /-\\     ��  ��   ���D��    ��ҳ  ",
    "     O       O O           |   Ƶ�� ",  // 16-20
    "     �J     �I��K     �L  |   ��̬ ",
    "   ��      �X���[   ������ | ��Ա�� ",
    "   \\  /    �X�D�[   ���D�� |  �ҵ�  ",
    " ",
    "#################################################"
    "#                       #��ԭ�񡷽�ɫչʾ- [��  #"
    "#                       #�꣺�����ع�]          #"
    "#                       #[5�����]              #"
    "#                       #[up] ԭ��              #"
    "#                       #[��] 65.6 �ۿ�        :#"
    "#__________________2:06_#########################",  // 21-25
    "#################################################"
    "#                       #ʵ������! 2020��Ȱٴ� #"
    "#                       #UP���񽱸��Ե�һ��...  #"
    "#                       #[5�����]              #"
    "#                       #[up] ��������UP��ִ��  #"
    "#                       #[��] 54   �ۿ�        :#"
    "#__________________8:29_#########################",
    "#################################################"
    "#                       #��Ҳ����Ů  !Ϸ��Ϸ��  #"
    "#                       #���˫��!Ӳ���²ۡ�... #"
    "#                       #                       #"
    "#                       #[up] ��������          #"
    "#                       #[��] 41.1  �ۿ�       :#"
    "#__________________9:11_#########################",
    "#################################################"
    "#                       #��ţ��ŮѧԱ��1965�֣� #"
    "#                       #��������ȫ�̺��ֱײ.. #"
    "#                       #                       #"
    "#                       #[up] ��ʵ��������˵��  #"
    "#                       #[��] 87.8  �ۿ�       :#"
    "#__________________1:13_#########################",
    "    ��      ����      ������    ���а�  ",
    "   \\��/      (��)       ��     ��վ��ˢ ",  // 26-30
    " +------+  |::  ��|  +------+  ÿ�ܱؿ� ",
    " �� ��     �X�D�[�[  ���D����  ��ȶ��� ",
    " ",
    "���",
    "����00000",  // 31-35
    "( ���ҷ���Ļ |",
    "�� )",  //��
    " [����] ����N                            [ͷ��] xxxx��˿                  "
    "      ",
    "��----����+��ע ",
    " ��������䡿 bad appleԭ�����1440*1080         ^ "
    " -----------------------------------------         "
    " {��}[25.5��] {��}[2321] 1-12 BV1Wx411c7JT         "
    " ��δ��������Ȩ��ֹת��                            "
    " ------------------------------------------------- ",  // 36-40
    "   ��     ���ϩߩ� ���ߩ���  ����   ",
    " �������� ���ǩש�   ��     ��ϲ��  ",
    "  ��      (��)      ��       Ͷ��   ",
    "   ��     ����    ���     �ղ�   ",
    "   _��     (/��              ����   ",  // 41-45
    " ",
    " ",
    "#################################################"
    "#                       #��ȷ����������ˮ�󻬼� #"
    "#                       #                       #"
    "#                       #                       #"
    "#                       #[up]                   #"
    "#                       #[��] 87.8  �ۿ�       :#"
    "#################################################",
    "#################################################"
    "#                       #(�|���ܷNTokyo Ghoul)  #"
    "#                       #Unravel-֣�ɺ�-ָ��..  #"
    "#                       #                       #"
    "#                       #[up] ֣�ɺ�            #"
    "#                       #[��] 87.8  �ۿ�       :#"
    "###################4:26##########################",
    " ",  // 46-50
    " ",
    " ",
    " ",
    "#################################################"
    "# [����]  ����N lv6 UP                          #"
    "# [ͷ��]                                        #"
    "#         �ʳ���Ǹ����ʱû������                #"
    "#         ######################                #"
    "#         ��00000���ظ� >                      :#"
    "#################################################",
    "#################################################"
    "# [ͷ��]  ����N lv6 UP                          #"
    "# [һ��]                                        #"
    "#         �ʳ���Ǹ����ʱû������                #"
    "#         ######################                #"
    "#         ��00000���ظ� >                      :#"
    "#################################################",  // 51-55
    "#################################################"
    "# [ͷ��]  ����N lv6 UP                          #"
    "# [һ��]                                        #"
    "#         �ʳ���Ǹ����ʱû������                #"
    "#         ######################                #"
    "#         ��00000���ظ� >                      :#"
    "#################################################",
    "#################################################"
    "# [�������Ƶ�����                     ]     0v0 #"
    "#################################################",
    " ��������                               ����ʱ�� ",
    " ",
    " ",  // 56-60
    " ",
    " ",
    " ",
    " ",
};
//�ṹ�����
struct User {
    int uid;           // bվuid
    char head[L * L];  //ͷ��
    char userName[N];  //�û���
    int coin;          //Ӳ����
    int lv;            // bվ�ȼ�
    //�±�0λ�Ǽ���λ��������Ϣ
    int concern[M];        //��ע
    int follower[M];       //��˿
    int myVideos[M];       //�ҵ���Ƶ
    int collectVideos[M];  //���ղص���Ƶ
};

struct Vedio {
    int vid;              //��ƵΨһ���
    char title[N];        //����
    char intro[2 * N];    //���
    char cover[LL * LL];  //����
    //��Ƶͳ����/�ۿ�/����/Ͷ��/�ղ�/
    int viewNum, likeNum, coinNum, collectNum;
    char viewTime[N];  //#����ʱ��
    char comment[M];   //#����
};
//һЩϵͳ���ܺ���
void HideCursor()  //�������
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};  //��ߵ�0�����겻�ɼ�
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)  //�ù���ƶ�������ȥ��ӡ���ݺ���
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
void fixedWindow() {                 //���Ժ���
    HWND hWnd = GetConsoleWindow();  //���cmd���ھ��
    RECT rc;
    GetWindowRect(hWnd, &rc);  //���cmd���ڶ�Ӧ����
    //�ı�cmd���ڷ��
    SetWindowLongPtr(hWnd, GWL_STYLE,
                     GetWindowLong(hWnd, GWL_STYLE) & ~WS_THICKFRAME &
                         ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
    //��Ϊ����漰���߿�ı䣬�������SetWindowPos��������Ч��
    SetWindowPos(hWnd, NULL, rc.left, rc.top, rc.right - rc.left,
                 rc.bottom - rc.top, NULL);
}
void setColor(short x)  //�Զ��庯���ݲ����ı���ɫ
{
    // if (x >= 0 && x <= 15) //������0-15�ķ�Χ��ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            x);  //ֻ��һ���������ı�������ɫ
    /* else                              //Ĭ�ϵ���ɫ��ɫ
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);*/
}
//һЩϵͳ���ܺ���

void debug() {
    static int x = 0, y = 0;
    static char flag = '#';
    //�������־ͻ��л�����Ӧ�Ķ�����ӡ���㻭��
    char print[11] = " !@#$%^&*(";
    int nextgo[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};  //˳ʱ��wdsa��һ�����ƶ�
    int bookMap[128] = {0};
    bookMap['w'] = 0, bookMap['d'] = 1;
    bookMap['s'] = 2, bookMap['a'] = 3;
    gotoxy(y, x), printf("%c", flag);
    char turn = _getch();
    if (turn == ' ')
        system("cls");
    else if (turn >= '0' && turn <= '9')
        flag = print[turn - '0'];
    else {
        x += nextgo[bookMap[turn]][0];
        y += nextgo[bookMap[turn]][1];
        gotoxy(y, x), printf("_");
        gotoxy(0, 20), printf("x=%d y=%d nowturn='%c'", x, y, flag);
    }
}
void printCuttingLine(int deep, char wall = '-') {  ///��ӡ�ָ���
    for (int i = 1; i < WIDTH - 1; i++) {
        gotoxy(i, deep);
        printf("%c", wall);
    }
}
//��ӡ�����������
void printBoder() {  //��ӡ�߿�
    setColor(Boder_Color);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            gotoxy(j, i);
            if (i == 0 || i == HEIGHT - 1)
                printf("#");
            else if (j == 0 || j == WIDTH - 1)
                printf("#");
        }
    }
    setColor(Normal_Color);
        //��ӡpage���÷ָ���
    int mapHeight = appMap[nowPage][0][0];  //��ȡ��ͼ�߶�
    int cuttingLine =
        appMap[nowPage][mapHeight][0];  //�����һ��0λ��ȡ�ָ��߸���
    for (int i = 0; i < cuttingLine; i++) {
        printCuttingLine(appMap[nowPage][mapHeight][i + 1]);
    }
}

//�����ַ���ӡģ��
void printDemo(int index, bool on = false) {
    int x = appMapMessage[index][0];
    int y = appMapMessage[index][1];
    int h = appMapMessage[index][2];
    int w = appMapMessage[index][3];
    int turn = appMapMessage[index][4];  //��ȡ��дͼ��״̬
    char prePrint[h + 1][WIDTH];
    int cnt = 0;
    if (turn) {
        for (int i = 0; i < h; i++) {
            strncpy(prePrint[i], appMapIcon[index] + w * i, w);
            prePrint[i][w] = '\0';
            gotoxy(y, x + i);
            printf("%s", prePrint[i]);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            gotoxy(y + j, x + i);
            if (!on) {  //δ��ѡ��״̬
                if (!turn) {
                    printf("#");
                }  //ʲô��û�е�����ҳ
                else if (turn == 1 &&
                         (activeIndexTop == index ||
                          activeIndexBottom == index) &&
                         j == 0) {
                    gotoxy(y + j, x + i);
                    setColor(Is_Active_Color);
                    printf("%s", prePrint[i]);
                    setColor(Normal_Color);
                }
                // printf("%c",str[index++]);
            } else {
                if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                    //�����ǰ����ҳ�Ƽ���ǩ����ô�Ƽ���ǩӦ���ǳ�����active״̬
                    //��������ѡ��״̬
                    if (turn == 1 && j == 0) {
                        gotoxy(y + j, x + i);
                        if (index >= 9 && index <= 14 ||
                            index >= 21 && index <= 24 ||
                            index >= 43 && index <= 45) {
                            setColor(Video_Color);
                        }  //��Ƶ����ʽ
                        else if (index >= 15 && index <= 19 ||
                                 index >= 25 && index <= 28 ||
                                 index >= 37 && index <= 41 || index == 35) {
                            setColor(Is_Selected3_Color);
                        }  //һЩ��λ�ַ�����ʽ
                        else
                            setColor(Is_Selected1_Color);  //������ʽ
                        printf("%s", prePrint[i]);
                        // printf("%c",str[index++]);
                    }else if (turn == 0) {
                    setColor(Is_Selected2_Color);
                    printf("O");
                	}
                } 
	            else {
	                if (!turn)
	                    printf("#");
	            }
	            setColor(Normal_Color);
            }
        }
    }
    if (!on && !turn) {
        gotoxy(20, 20);
        printf("�� �� �� Ǹ ");
        gotoxy(14, 22);
        printf("�� Ҫ �� �� ҳ �� �� �� ��");
        gotoxy(17, 24);
        printf("�� �� �� �� �� �� ��");
        gotoxy(17, 26);
        printf("�� q �� �� �� һ ҳ");
    }
}
void clsPage() {
    //�˴�д������߿����
    system("cls");
}
void loadPage() {         //������ҳ�˵�
    int book[100] = {0};  //αԤ���أ����ع��Ľ���Ͳ��ټ���
    printBoder();
    int h = appMap[nowPage][0][0] - 2;  //��ȥ����ǽ��
    int w = 5;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int index = appMap[nowPage][i][j];  //��ȡ��Ӧģ��Ķ�Ӧֵ
            if (!book[index])
                printDemo(index, false);
            book[index] = 1;
        }
    }
}

void checkAction(int action) {  //����·����ת
    if (action == 3) {          //��Ϣ��
        nowPage = 5;
    } else if (action == 5) {  //��ҳ
        nowPage = 1;
    } else if (action == 6) {  //����
        nowPage = 2;
    } else if ((action >= 9 && action <= 14) ||
               (action >= 21 && action <= 24)) {
        onPlay = true;
        nowPage = 4;                            //������Ƶ��ϸҳ��
    } else if (action >= 15 && action <= 19) {  //�ײ��ǩ��
        if (action == 15) {
            activeIndexBottom = 15;  //��Ӧ�����ҳ
            activeIndexTop = 5;
            nowPage = 1;  //ûд�����ȷ���ҳ �����nowPageҪ��Ӧ����
        } else
            nowPage = 0;
    } else if (action == 29) {  //�����Ƶģ��  ���Ӧֹͣ��Ƶ
        if (!stopPlay)
            stopPlay = true;
        else
            stopPlay = false;
    } else {
        nowPage = 0;  // ûд�Ľ���404
    }
    activeIndexTop = action;  //�ж������л���
}

void move() {
    //�����ʼ����
    static int x = 1, y = 1;
    static int oldPage = nowPage;
    int oldX = x, oldY = y;
    int nextgo[5][2] = {0, 0, -1, 0, 0,
                        1, 1, 0,  0, -1};  //˳ʱ��wdsa��һ�����ƶ�
    int bookMap[128] = {0};
    bookMap['w'] = 1, bookMap['d'] = 2;
    bookMap['s'] = 3, bookMap['a'] = 4;
    //ȡ����ǰλ��
    //һ��index�±�λ�þʹ洢��һ��action
    int index = appMap[nowPage][x][y];
    int oldIndex = index;
    printDemo(index, false);  //�����ϴε�λ��
    char turn = _getch();
    x += nextgo[bookMap[turn]][0];
    y += nextgo[bookMap[turn]][1];
    index = appMap[nowPage][x][y];
    if (index == 0) {  //����Ǳ߽������
        x = oldX, y = oldY;
    } else {  //������ƶ�����һ���µ�λ��
        while (oldIndex == index && index != 0 && bookMap[turn] != 0) {
            x += nextgo[bookMap[turn]][0];
            y += nextgo[bookMap[turn]][1];
            index = appMap[nowPage][x][y];
        }  // while��������ռ��������״̬
        if (index == 0)
            x = oldX, y = oldY;
    }
    index = appMap[nowPage][x][y];
    printDemo(index, true);  //��ӡ�µ�״̬
    if (turn == ' ' || turn == 'q') {
        if (turn == ' ') {
            checkAction(index);
        } else {
            onPlay = false;
            stopPlay = true;
            nowPage = 1;  //�ص���ҳ
        }

        if (nowPage != oldPage) {  //����仯
            oldPage = nowPage;
            x = 1;
            y = 1;
            clsPage();   //���˱߿�ȫ������
            loadPage();  //�����½���
        }
    }
}
void playVideo() { //Ϊ�Խ���Ҫ�����ļ� 
    int w = 51;             //���
    int h = 14;             //�߶�
    int PAGE_LIMIT = 4023;  //֡��
    int N = w * h;          //�ַ���
    char str[N];
    char name[] = "badapple/ASCII-���� 010001.txt";  // 13 14 15 16λ
    int imageNum, tempNum, n = 1, p, q;
    //֡����
    for (imageNum = 1; imageNum <= PAGE_LIMIT; imageNum++) {
        if (!onPlay)
            return;      //ɱ���߳��򷵻�
        if (stopPlay) {  //ֹͣ��������ͣ
            if (imageNum > 0)
                imageNum--;
        } else {
            int tempNum = imageNum;
            for (p = 0; p < 4; p++) {
                int num = tempNum % 10;  //��ȡ��p+1λ
                tempNum /= 10;
                name[25 - p] = num + '0';
            }
            FILE* fp;
            //���ı�
            if ((fp = fopen(name, "r")) == NULL) {
                printf("%d", imageNum);
                system("pause");
                continue;
            }
            //��ȡ�ı�
            int line = 1;
            while (fgets(str, N, fp) != NULL) {
                gotoxy(1, line++);
                printf("%s", str);
            }
            //�ر��ı�
            fclose(fp);
        }
        int timeLimit = 1000;
        while (timeLimit--) {
            if (kbhit())
                move();
        }
        // system("cls");
    }
}
void init() {
    char cmd[50];
    sprintf(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
    printf("%s", cmd);
    system(cmd);         //���ý����С
    system("color 07");  //���ý�����ɫ��
    fixedWindow();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            gotoxy(j, i);
            printf("%c", bacground[i][j]);
        }
    }
    printBoder();
    getchar();
    system("cls");
    loadPage();
    HideCursor();
}

int main() {
    // ctrl+���ֿ��Ե������
    init();
    while (1) {
        if (onPlay) {
            playVideo();
        }
        if (kbhit()) {
            // debug(); //����debug�ͻ���ʾ������Ϣ������ע��move()
            move();
        }
    }
}
// 7  - 41
