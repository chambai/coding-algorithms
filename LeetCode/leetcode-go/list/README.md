## 链表介绍

链表通常包括：

- 单链表，包含 next 域
- 双链表，包含 next 和 pre 域
- 环形链表，tail 的 next 域指向 head，形成一个环

链表相关的核心点：

- null/nil 的异常处理
- dummy node 哑巴节点
- 快慢指针
- 插入
- 删除
- 翻转
- 合并
- 找链表的中间节点
- 找链表的环入口点
- ......



## 题目

### [01 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/deleteDuplicates.go)

### [02 删除排序链表中的重复元素 II(只保留不相同的)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/deleteDuplicatesSame.go)

### [03 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/removeNthFromEnd.go)

### [04 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/reverseList.go)

### [05 反转链表 II(指定一个区间)](https://leetcode-cn.com/problems/reverse-linked-list-ii/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/reverseBetween.go)

### [06 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/mergeTwoLists.go)

### [07 分隔链表(从指定x处分隔)](https://leetcode-cn.com/problems/partition-list/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/partition.go)

### [08 排序链表(O(nlogn)时间复杂度)](https://leetcode-cn.com/problems/sort-list/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/sortList.go)

### [09 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/hasCycle.go)

### [10 环形链表 II(找环的入口)](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/detectCycle.go)

### [11 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/isPalindrome.go)

### [12 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

**go 语言实现：** [参考]()

### [13 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/swapPairs.go)

### [14 重排链表](https://leetcode-cn.com/problems/reorder-list/)

> 题目描述：
>
> 给定一个单链表 L：*L0*→*L1*→…→*Ln-1*→*Ln*，
>
> 将其重新排列后变为：*L0*→*Ln*→*L1*→*Ln-1*→*L2*→*Ln-2*→…
>
> 要求：
>
> 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。不开辟额外空间。



**思路：** 这道题考到逆序排列，可以配合栈来做还是比较方便的。但题目要求不开额外空间，就只能在链表上做文章。仔细看这个链表可以分为前后两个链表，由链表中点分开，后面的链表进行逆序，然后插入到前面的链表中。所以解决思路就是：

- 找到链表中点，从中点将链表分为前后两个链表
- 将后一个链表原地逆序
- 将后一个链表插入到前一个链表中

**go 语言实现：** [参考](https://github.com/ctimbai/coding-algorithms/blob/master/LeetCode/leetcode-go/list/reorderList.go)

