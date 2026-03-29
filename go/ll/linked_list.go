package ll

type LinkedList[T any] struct {
	base *Node[T]
}

func LL_New[T any](data T) LinkedList[T] {
	n := N_New(data)

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
	new := N_New(data)
	ll.PushNode(new)
}
