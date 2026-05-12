class TreeNode {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

function GetTargetNode(root, target, parent_map) {
  const queue = [];
  let res = null;
  queue.push(root);
  while (queue.length > 0) {
    const node = queue.shift();
    if (node.data === target) res = node;
    if (node.left) parent_map.set(node.left, node);
    if (node.right) parent_map.set(node.right, node);
  }
  return res;
}

function getTime(parentMap, targetNode) {
  if (!targetNode) return 0; // safety

  const queue = [];
  const visited = new Map();

  let count = 0;

  queue.push(targetNode);
  visited.set(targetNode, true);

  while (queue.length > 0) {
    let size = queue.length;
    let flag = false;

    for (let i = 0; i < size; i++) {
      const node = queue.shift();
      if (!node) continue; // 🔥 important fix

      if (node.left && !visited.get(node.left)) {
        queue.push(node.left);
        visited.set(node.left, true);
        flag = true;
      }

      if (node.right && !visited.get(node.right)) {
        queue.push(node.right);
        visited.set(node.right, true);
        flag = true;
      }

      const parent = parentMap.get(node);
      if (parent && !visited.get(parent)) {
        queue.push(parent);
        visited.set(parent, true);
        flag = true;
      }
    }

    if (flag) count++;
  }

  return count;
}
function MinimumTime(root, target) {
  let parent_map = new Map();
  const target_node = GetTargetNode(root, target, parent_map);
  return getTime(parent_map, target_node);
}

const root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.left.right = new TreeNode(7);
root.right.right = new TreeNode(6);
root.right.left = new TreeNode(5);

console.log(MinimumTime(root, 2));
