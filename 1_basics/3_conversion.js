// Conversisons
let age="hitesh";
console.log(typeof age);
console.log(typeof(age));
let valueInNumber=Number(age);
console.log(typeof valueInNumber);
console.log(valueInNumber); 

// "33"=>33
// "33abc"=> NaN not a Number
// true=>1; false=>0
// null=>0
// undefined=>NaN

let loggedIn="hitesh";
let booleanloggedin=Boolean(loggedIn);
console.log(booleanloggedin); 

// 1=>true; 0=>false
// ""=>false
// "hitesh"=>true

let someNumber=33;
let stringnumber=String(someNumber);
console.log(typeof stringnumber);

// 33=>"33"


// Opeartions

let value=3
let negvalue=-value;
// console.log(negvalue);


console.log(2+2);
console.log(2-2);
console.log(2*2);
console.log(2**2);   // power 2 res to 2
console.log(2**3);   // power 2 res to 2
console.log(2/2);
console.log(2%2);

let str1="hello ";
let str2="hitesh";
let str3=str1+str2;
console.log(str3);

console.log("1"+2);
console.log("1"+"2");
console.log("1"+2+2);
console.log(2+2+"1");

console.log(+true); // output: 1
console.log(true); // output: true

let num1,num2,num3;

num1=num2=num3=2+2;

let gamecounter=100;
gamecounter++;
console.log(gamecounter);

let x = 3;
const y = x++;

console.log(`x:${x}, y:${y}`);
// Expected output: "x:4, y:3"

let a = 3;
const b = ++a;

console.log(`a:${a}, b:${b}`);
// Expected output: "a:4, b:4"
