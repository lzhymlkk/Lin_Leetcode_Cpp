#include<iostream>
#include<vector>
#include<map>
using namespace std;
//以下这个是暴力法，时间复杂度为O(n²)
//在C++中，vector数组对象后面加.size，获取数组的元素个数
//vector数组对象的名字表示的就是一个数组对象，而非数组的首地址！这是因为数组对象不是数组，而是封装了的数组
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
		//为什么i要从0开始呢，因为为了对标下面的num[i]。为什么要用小于号，且减一呢？因为后面是i++，实际上进行了nums.size次循环
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                   return {i,j};
                }
            }
        }
        return {};
    };
};
//下面介绍的是哈希表法，哈希表的时间复杂度为O(n)
//map是一个单重关联容器&二元关联容器，意思是“映射” ，有insert,erase等成员函数
//value_type是指迭代器所指对象的型别
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;//建立hash表存放数组元素
        vector<int> b(2,-1);//这是用来存放结果的数组对象，-1是为数组里所有对象指定的初值，否则，就要都以0为初值
        for(int i=0;i<nums.size();i++)
            a.insert(map<int,int>::value_type(nums[i],i));//把值和键分别存储到map映射里
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i))
            //判断是否找到目标元素且目标元素不能是本身
            {
                b[0]=i;
                b[1]=a[target-nums[i]];
                break;
            }
        }
        return b;
    };
};


int main()
{
    return 0;
}
