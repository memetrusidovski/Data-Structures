"""
-------------------------------------------------------
This is a Stack implimentation.
-------------------------------------------------------
"""
from copy import deepcopy


class Node:

    def __init__(self, value, next_):
        """
        -------------------------------------------------------
        Initializes a stack node that contains a copy of value
        and a link to the next node in the stack.
        Use: node = _Stack_Node(value, _next)
        -------------------------------------------------------
        Parameters:
            value - value for node (?)
            next_ - another Stack node (_Stack_Node)
        Returns:
            a new _Stack_Node object (_Stack_Node)
        -------------------------------------------------------
        """
        self._value = deepcopy(value)
        self._next = next_

class Stack:

    def __init__(self):
        """
        -------------------------------------------------------
        Initializes an empty stack. Values are stored in a 
        linked structure.
        Use: source = Stack()
        -------------------------------------------------------
        Returns:
            a new Stack object (Stack)
        -------------------------------------------------------
        """
        self.height = 0
        self._top = None

    def push(self, value):
        """
        -------------------------------------------------------
        Pushes a copy of value onto the top of source.
        Use: source.push(value)
        -------------------------------------------------------
        Parameters:
            value - value to be added to source (?)
        Returns:
            None
        -------------------------------------------------------
        """
        self._top = _Stack_Node(value, self._top)
        return

    def pop(self):
        """
        -------------------------------------------------------
        Pops and returns the top of stack. The value is removed
        from source. Attempting to pop from an empty stack
        throws an exception.
        Use: value = source.pop()
        -------------------------------------------------------
        Returns:
            value - the value at the top of stack (?)
        -------------------------------------------------------
        """
        assert self._top is not None, "Cannot pop from an empty stack"

        value = self._top._value
        self._top = self._top._next
        return value