#include<iostream>
using namespace std;
/*题目描述：给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字0之外，这两个数都不会以0开头。
示例：输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807*/
/*如何正确的分析这道题？
首先，我们要从最低位有效位，也就是链表的表头开始相加，这里就可能会出现溢出的情况。
这时候，我们就需要设置一个进位标志，设为carry，它的初值为0.
*/
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}     //这一行特别关键！结构体的初始化！否则会报错！
};

ListNode* addTwoNumbers(ListNode* a1, ListNode* a2) {
    ListNode *head, *curr;
    head = curr = new ListNode(0);
    bool carry = false;//carry是一个布尔型变量

    while (true)    //一直循环执行！直到碰到break
    {
      ListNode* node  = new ListNode(0);//这个是初始化一个值为0的空结点node
      int v1, v2;

      if (carry)  node->val = 1;
      else   node->val = 0;

      carry = false;

      if (a1 != NULL){v1 = a1->val;a1 = a1->next;}//a1一开始是在头结点，也就是个位的结点，先把它的值传给v1，然后指向下一个结点
      else  v1 = 0;

      if (a2 != NULL){v2 = a2->val;a2 = a2->next;}
      else  v2 = 0;

      carry     = (node->val + v1 + v2) / 10;
      node->val = (node->val + v1 + v2) % 10;//node是存放余数的

      curr->next = node;
      curr       = node;

      if (a1 == NULL && a2 == NULL && !carry)//这一点非常重要！不仅要两个结点为空，还要保证最后的相加没有进位才行
        break;
    }

    return head->next;
  }
  int main(){
    return 0;
  }

