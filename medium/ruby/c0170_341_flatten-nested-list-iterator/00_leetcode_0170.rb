# DRUNKWATER TEMPLATE(add description and prototypes)
# Question Title and Description on leetcode.com
# Function Declaration and Function Prototypes on leetcode.com
#341. Flatten Nested List Iterator
#Given a nested list of integers, implement an iterator to flatten it.
#Each element is either an integer, or a list -- whose elements may also be integers or other lists.
#Example 1:
#Given the list [[1,1],2,[1,1]],
#By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
#Example 2:
#Given the list [1,[4,[6]]],
#By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
## This is the interface that allows for creating nested lists.
## You should not implement it, or speculate about its implementation
##
##class NestedInteger
##    def is_integer()
##        """
##        Return true if this NestedInteger holds a single integer, rather than a nested list.
##        @return {Boolean}
##        """
##
##    def get_integer()
##        """
##        Return the single integer that this NestedInteger holds, if it holds a single integer
##        Return nil if this NestedInteger holds a nested list
##        @return {Integer}
##        """
##
##    def get_list()
##        """
##        Return the nested list that this NestedInteger holds, if it holds a nested list
##        Return nil if this NestedInteger holds a single integer
##        @return {NestedInteger[]}
##        """
#class NestedIterator
#    # @param {NestedInteger[]} nested_list
#    def initialize(nested_list)
#    end
#    # @return {Boolean}
#    def has_next
#    end
#    # @return {Integer}
#    def next
#    end
#end
## Your NestedIterator will be called like this:
## i, v = NestedIterator.new(nested_list), []
## while i.has_next()
##    v << i.next
## end



# Time Is Money