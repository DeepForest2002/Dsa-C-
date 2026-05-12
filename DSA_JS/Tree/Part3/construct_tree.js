class TreeNode{
    constructor(data) {
        this.data = data;
        this.left = this.right = null;
    }
}



function buildTree(preOrder,inOrder) {
    const inMap = new Map();
    for (let i = 0; i < inOrder.length; i++){
        inMap.set(inOrder[i], i);
    }
    const rootNode = build(preOrder, 0, preOrder.size - 1, inOrder, 0, inOrder.length - 1, inMap);
    return rootNode;
}

function build(preOrder, preStart, preEnd, inOrder, inStart, inEnd, inMap) {
    if (preStart > preEnd || inStart > inEnd) return null;
    const rootNode = new TreeNode(preOrder[preStart]);
    let inRoot = inMap.get(rootNode.data);
    let numsLeft = inRoot - inStart;

    rootNode.left= build(preOrder,)
}

const preOrder=[3,9,10,15,7]
const inOrder = [9, 3, 15, 20, 7]

const root = buildTree(preOrder, inOrder)

preOrder.length