# DRUNKWATER TEMPLATE(add description and prototypes)
# Question Title and Description on leetcode.com
# Function Declaration and Function Prototypes on leetcode.com
#654. Maximum Binary Tree
#Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
#The root is the maximum number in the array.
#The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
#The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
#Construct the maximum tree by the given array and output the root node of this tree.
#Example 1:
#Input: [3,2,1,6,0,5]
#Output: return the tree root node representing the following tree:
#      6
#    /   \
#   3     5
#    \    / 
#     2  0   
#       \
#        1
#Note:
#The size of the given array will be in the range [1,1000].
## Definition for a binary tree node.
## class TreeNode
##     attr_accessor :val, :left, :right
##     def initialize(val)
##         @val = val
##         @left, @right = nil, nil
##     end
## end
## @param {Integer[]} nums
## @return {TreeNode}
#def construct_maximum_binary_tree(nums)
#end



# Time Is Money