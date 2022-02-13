// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carry;
        int init_flag = 0;
        sum = 0;
        carry = 0;
        
        //ListNode *sum_out = (ListNode *) malloc(sizeof(ListNode));
        ListNode* sum_out = new ListNode();
        ListNode *node, *prev_node;
        ListNode *l1_node, *l2_node;
        node = nullptr;
        prev_node = nullptr;
        l1_node = l1;
        l2_node = l2;

        while (l1_node != nullptr || l2_node != nullptr)
        {
         
            if (!init_flag) {
                node = sum_out;
                init_flag = 1;
            }
            else {
                node = new ListNode();
                prev_node->next = node;
             
            }
            prev_node = node;

            if (l1_node != nullptr && l2_node != nullptr) {
                sum = l1_node->val + l2_node->val + carry;
                l1_node = l1_node->next;
                l2_node = l2_node->next;
            }
            else  if (l1_node != nullptr) {
                sum = l1_node->val + carry;
                cout << sum << endl;
                l1_node = l1_node->next;
            }
            else
            {
                sum = l2_node->val + carry;
                cout << sum << endl;
                l2_node = l2_node->next;
            }
            if (sum > 9)
                carry = 1;
            else carry = 0;
            sum = sum % 10;
            node->val = sum;

        }//while

        if (carry)
        {
            node->next = new ListNode();
            node->next->val = carry;
        }
         return sum_out;
    }



    ListNode* createNumber(int num, int size)
    {
        //ListNode* p_node = (ListNode*)malloc(sizeof(ListNode));
        ListNode* p_node = new ListNode();
        ListNode *node, *prev_node;
        node = nullptr;
        prev_node = nullptr;
        if (size > 0) {
            for (int i = size - 1; i >= 0; i--) {
                if (i == size - 1)
                {
                    node = p_node;
                }
                else
                {
                    //node = (ListNode*)malloc(sizeof(ListNode));
                    node = new ListNode();
                    prev_node->next = node;
                }
                prev_node = node;
                int base = pow(10, i);
                node->val = num / base;
                num = num % base;
            }
        }
        return p_node;
    }

    void display(ListNode* num)
    {
    
        while (num != nullptr)
        {
            cout << num->val;
            num = num->next;
        }
        cout << endl;
    }


};


int main()
{
    std::cout << "Hello World!\n";
    Solution sol;
    ListNode* num1 = sol.createNumber(934, 3); 
    ListNode* num2 = sol.createNumber(1024, 4);
    ListNode* sum  = sol.addTwoNumbers(num1, num2);
    sol.display(sum);
    delete num1;
    delete num2;
    delete sum;

    num1 = sol.createNumber(999, 3);
    num2 = sol.createNumber(999, 3);
    sum = sol.addTwoNumbers(num1, num2);
    sol.display(sum);
    delete num1;
    delete num2;
    delete sum;


    num1 = sol.createNumber(10, 0);
    num2 = sol.createNumber(10, 0);
    sum = sol.addTwoNumbers(num1, num2);
    sol.display(sum);
    delete num1;
    delete num2;
    delete sum;

    num1 = sol.createNumber(9, 1);
    num2 = sol.createNumber(9, 1);
    sum = sol.addTwoNumbers(num1, num2);
    sol.display(sum);
    delete num1;
    delete num2;
    delete sum;


   //ListNode chk1 = ListNode(9);
   //ListNode chk2 = ListNode(1);
   //cout << (chk1.val + chk2.val) << endl;
   //
   //ListNode *chk3 = new ListNode(9);
   //ListNode *chk4 = new ListNode(1);
   //cout << (chk3->val + chk4->val) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
