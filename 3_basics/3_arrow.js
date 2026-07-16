const user={
    username:"hitesh",
    price:999,
    welcomeMessage:function(){
        console.log(`${this.username}, welcome to website`); // this-current context ne refer kare che 
        // console.log(this);
          
    }
}
// user.welcomeMessage()
// user.username="sam";
// user.welcomeMessage()

// console.log(this);



// function chai(){
//     let username="hitesh"
//     console.log(this.username);
// }
// chai()

// const chai=function(){
//     let username="hitesh"
//     console.log(this.username);
// }
// chai()

// const chai=()=>{
//     let username="hitesh";
//     console.log(this);
// }
// chai()

const addtwo=(num1,num2)=>{
return num1+num2;
}
console.log(addtwo(2,4));

const add=(num1,num2)=> (num1+num2); // implicit return jema return na lakhiye 
console.log(add(2,4));

// explicit return ma return lakhiye

const addition=()=> ({username:"hitesh"}); // implicit return jema return na lakhiye 
console.log(addition());


const array=[2,5,3,7,8]
// array.forEach(function(){})
// array.forEach(()=>{})
// array.forEach(()=>())
