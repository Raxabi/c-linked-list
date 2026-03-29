package ll

type LinkedList[T any] struct {
	base *Node[T]
}

func LL_New[T any](data T) LinkedList[T] {
	n := N_New(0, data)

	return LinkedList[T]{
		base: &n,
	}
}

func (ll *LinkedList[T]) GetLast() *Node[T] {
	n := ll.base

	for n.Next != nil {
		n = n.Next
	}

	return n
}

func (ll *LinkedList[T]) PushNode(node Node[T]) {
	n := ll.GetLast()
	n.Next = &node
}

func (ll *LinkedList[T]) PushData(data T) {
	last := ll.GetLast()
	new := N_New(last.idx+1, data)
	last.Next = &new
}
