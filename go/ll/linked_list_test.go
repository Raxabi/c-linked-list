package ll_test

import (
	"fmt"
	"testing"

	"github.com/Raxabi/go-ll/ll"
)

func TestCreateLL(t *testing.T) {
	list := ll.LL_New("12345")

	list.PushData("Hola a todos")
	fmt.Println(list.GetLast().Data)
}
