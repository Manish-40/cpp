// singleton
// literel thi banaviye to singleton nahi bane
// constructor thi banavyu to singleton banse

// objects literals
// Object.create // aane constructor thi banavyu kevay jema singleton banse


const mysym=Symbol("key1")
const jsuser={
    name:"Hitesh",
    "full name":"hitesh choudhary",
    [mysym]:"mykey1",
    age:18,
    location:"Jaipur",
    email:"hitesh@google.com",
    isLoggedIn:false,
    lastLoggedinDays:["Monday","Saturday"]
}

console.log(jsuser.email);
console.log(jsuser["email"]);
console.log(jsuser["full name"]);
console.log(jsuser[mysym]);

jsuser.email="hitesh@chatgpt.com";
// Object.freeze(jsuser); // Object.freeze thi object jsuser modify nahi thai sake
jsuser.email="hitesh@microsoft.com";
console.log(jsuser);


jsuser.greeting=function()
{
    console.log("hello js user");
}
console.log(jsuser.greeting); // khali reference madse function nu
console.log(jsuser.greeting()); // aana thi function call thase to function na andar nu console.log bhi print thase


jsuser.greeting2=function(){
    console.log(`hello js user,${this.name}`); //this thi object na andar  ni key made ke kaya object nu properties levu che
}

// consolo.log(``) aa back text(``) ne string interpolation bhi kahevay che

console.log(jsuser.greeting());
console.log(jsuser.greeting2());


