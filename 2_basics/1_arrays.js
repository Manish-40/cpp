// array

const myarray=[0,1,2,3,4,5]

// () - paranthesis
// {} - braces curly braces
// [] - brackets

// js ma array object typehoy che resizable hoy che aapde 1 var banavi ne change bhi kari skaiye che c++ jevu nahi k 1 var banavyu to pachi edit ke more elements nahi nakhi skaiye

// arrays - shallow copies aa aetle aapde bija ma reference aapyu to original bhi change thase 
// arrays - deep copies do not share the smae references 

console.log(myarray[1]);

const myheros=["shaktiman","nagraj"]
const myarr=new Array(1,2,3,4);

// Array methods

myarr.push(6)
myarr.push(7) // end ma push karse
myarr.pop() // value pop karse
myarr.unshift(9) // array na starting ma value add karse
myarr.shift() // starting value pop kari dese
console.log(myarr);
console.log(myarr.includes(9));
console.log(myarr.indexOf(3));

const newarray=myarr.join()
console.log(myarr);
console.log(typeof newarray);
console.log(newarray);

// slice, splice

console.log("A ",myarr);

const mynewarray=myarr.slice(1,3);

console.log(mynewarray);
console.log("B ",myarr);

const mynewarray2=myarr.splice(1,3); // aetli index ni value kadhi nakhse [1 2 3 4 5 6] => 2 3 4 kaydhi
console.log("C ",myarr); // value kadheli return karse [1,6]
console.log(mynewarray2);


