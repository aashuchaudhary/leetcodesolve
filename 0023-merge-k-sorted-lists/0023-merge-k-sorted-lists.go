/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// mergeKLists merges an array of k sorted linked lists into one sorted linked list.
func mergeKLists(lists []*ListNode) *ListNode {
    if len(lists) == 0 {
        return nil
    }

    for len(lists) > 1 {
        var temp []*ListNode
        for i := 0; i < len(lists); i += 2 {
            l1 := lists[i]
            l2 := (*ListNode)(nil)
            if i+1 < len(lists) {
                l2 = lists[i+1]
            }
            temp = append(temp, mergeLists(l1, l2))
        }
        lists = temp
    }

    return lists[0]
}

// mergeLists merges two sorted linked lists and returns the merged list.
func mergeLists(l1, l2 *ListNode) *ListNode {
    dummy := &ListNode{}
    node := dummy

    for l1 != nil && l2 != nil {
        if l1.Val > l2.Val {
            node.Next = l2
            l2 = l2.Next
        } else {
            node.Next = l1
            l1 = l1.Next
        }
        node = node.Next
    }

    if l1 != nil {
        node.Next = l1
    } else {
        node.Next = l2
    }

    return dummy.Next
}