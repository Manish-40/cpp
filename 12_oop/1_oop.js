const user = { // Object litral
    username: "hitesh",      //aa badhi properties che
    loginCount: 8,
    signedIn: true,
    getUserDetails:function(){  // aa method thai gayu
        console.log("Got user details from database");
        console.log(`Username: ${this.username}`);
        console.log(this);
    }
}
console.log(this);

// console.log(user.username);
// console.log(user.getUserDetails());

// upper nu object hatu object su hoy to collection of properties and methods


// const promiseOne=new Promise() // new constructor function che
// const date=new Date()

function User(username,loginCount,isLoggedIn){
    this.username=username;    // this.username variable che =username je function ma pass thayu che e che
    this.loginCount=loginCount;
    this.isLoggedIn=isLoggedIn;
    this .greeting=function(){
        console.log(`Welcome ${this.username}`);
    }

    // return this;
}

const userOne=new User("hitesh",12,true)
const userTwo=new User("chai aur code",11,false)
console.log(userOne.constructor); //new na lakhiye aem j User() value pass kari to usertwo ma overwrite kari dese
// console.log(userTwo);


// new keyword lakhiye to 1 empty object create thay jene instance kehvay {}
// console.log(userOne.constructor); aa constructor reference hoy potana j bare ma