function sayMyName() {
    console.log("H");
    console.log("I");
    console.log("T");
    console.log("E");
    console.log("S");
    console.log("H");
}
sayMyName(); 

// sayMyName aa thai gayu reference
// sayMyName() aa thai gayu function execution


// function add(number1,number2){
//     console.log(number1+number2);
// }

// function add(number1,number2){
//     let result=number1+number2
//     return result;
// }

function add(number1,number2){
    return number1+number2
}
const result=add(3,5)

console.log("Result: ",result);

function loginusermessage(username="sam")
{
    if(username===undefined)  //if(!username) same username===undefined
        {
            console.log("please enter a username");
            return;
        } 
        return `${username} just logged in`
}

console.log(loginusermessage("hitesh"));
console.log(loginusermessage(""));
console.log(loginusermessage());

function calculateCartPrice(val1,val2,...num1){  // ...num1 aanej spread operator ane rest operator kahevay che 
return num1;
}
console.log(calculateCartPrice(200,400,500,800));
// amna aane rest operator kahevay

const user={
    username:"hitesh",
    price:199
}

function handleObject(anyobject){
    console.log(`Username is ${anyobject.username} and price is ${anyobject.price}`);
}
// handleObject(user);
handleObject({
    username:"sam",
    price:399
});

const mynewarray=[200,400,100,800];

function returnSecondValue(getArray){
return getArray;
}
// console.log(returnSecondValue(mynewarray));
console.log(returnSecondValue([100,200,300,400]));