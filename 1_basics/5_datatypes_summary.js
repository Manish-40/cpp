// JS is Dynamically typed language kemke aama aapde let score=100 aama e pota thi type number le che aapde statically type nathi karta int score=100
// Primitive

// 7 types: String, Number, Boolean, null, Undefined, Symbol, BigInt


const score=100; 
const scorevalue=100.3;

const loggedin=false;
const outsidetemp=null;

let userEmail; //undefined
let email=undefined; // same userEmail
const id=Symbol('123');
const anotherid=Symbol('123');

console.table({score,scorevalue,loggedin});

console.log(id);
console.log(anotherid);
console.log(id===anotherid);

const bignumber=872163782481468213746173827472374834n;
console.log(typeof bignumber);

// Referense Type (Non Primitive)  aana badha datatypes function aave typesof ane function nu datatype object function aave typesof

//  Array, Objects, Functions

const heros=["shaktiman","naagraj","doga"];
let myobj={
    name:"hitesh",
    age:22,
}
console.log(myobj);

const myfunction=function(){
    console.log("hello function");
    
}
myfunction();

console.log(typeof outsidetemp);  // object
console.log(typeof scorevalue);


console.log(typeof heros); //object
console.log(typeof myobj); // object
console.log(typeof myfunction); // function object

console.log(typeof anotherid);



// Part:2 Stack (Primitive) and Heap (Non-Primitive) Memory

let myyoutubename="hiteshchoudhary"

let anothername=myyoutubename;
anothername="chai aur code";

console.log(myyoutubename);
console.log(anothername);

let user={
    email:"user@google.com",
    upi:"user@ybl"
}

let usertwo=user;

usertwo.email="hitesh@google.com"

console.log(user.email);
console.log(usertwo.email);














