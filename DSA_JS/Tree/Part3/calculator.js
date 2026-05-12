let number1 = 12;
let number2 = 13;

let operation = "+";

switch (operation) {
  case "+":
    console.log(number1 + number2);
    break;
  case "-":
    if (number1 >= number2) console.log(number1 - number2);
    else console.log(number2 - number1);
    break;
  case "*":
    console.log(number1 * number2);
    break;
  case "/":
    console.log(number1 / number2);
    break;
  case "%":
    console.log(number1 % number2);
}
