// promise
let promise = new Promise((resolve, reject) => {
  const ok = true;
  if (ok) {
    resolve("ok");
  } else {
    reject("not ok");
  }
});

promise
  .then((data) => {
    console.log(data);
  })
  .catch((error) => {
    console.log(error);
  });

let arr = [1, 2, 3, 4, 5];
let mapped_arr = arr.map((number) => number + 3);
let filter_arr = arr.filter((number) => number % 2 === 0);
let sum_elements = arr.reduce((prev, curr) => (curr = prev + curr));
console.log(sum_elements);
