public class Preorder {
    private static void preOrder(BinaryTreeNode<Base> tree) {
        if(tree != null) {
            VISIT(tree.getData());
            preOrder(tree.getLeft());
            preOrder(tree.getRight());
        }
    }
}