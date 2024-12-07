class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf && quadTree2->isLeaf) return new Node(quadTree1->val | quadTree2->val, true);
        if (quadTree1->isLeaf) return quadTree1->val == 1 ? quadTree1 : quadTree2;
        if (quadTree2->isLeaf) return quadTree2->val == 1 ? quadTree2 : quadTree1;
        Node* t1 = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* t2 = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* t3 = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* t4 = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (t1->isLeaf && t2->isLeaf && t3->isLeaf && t4->isLeaf && t1->val == t2->val && t2->val == t3->val && t3->val == t4->val)
            return new Node(t1->val, true);
        return new Node(0, false, t1, t2, t3, t4);
    }
};