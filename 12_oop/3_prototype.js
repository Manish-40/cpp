let myName="hitesh     ";
let myChannel="chai     ";
// console.log(myName.trim().length);
console.log(myChannel.truelength);


let myHeros=["thor","spiderman"]


let heroPower={
    thor:"hammer",
    spiderman:"sling",

    getSpiderPower:function(){
        console.log(`Spidy power is ${this.spiderman}`);
    }
}

Object.prototype.hitesh=function(){
    console.log(`hitesh is present in all object`);
}

Array.prototype.heyHitesh=function(){
    console.log(`Hitesh says hello`);
}
heroPower.hitesh()
myHeros.hitesh()

myHeros.heyHitesh()
// heroPower.heyHitesh()


// inheritance

const user={
    name:"chai",
    email:"chai@google.com"
}

const Teacher={
    makeVideo:true,
}

const teachingSupport={
    isAvailable:false
}

const TASupport={
    makeAssignment:'JS assignment',
    fulltime:true,
    __proto__:teachingSupport
}

Teacher.__proto__=user


// modern syntax
Object.setPrototypeOf(teachingSupport,Teacher)

let anotherUsername="chaiaurcode     ";

String.prototype.truelength=function(){
    console.log(`${this}`);
    console.log(`True length is: ${this.trim().length}`);
}

anotherUsername.truelength()
"hitesh".truelength()
"iceTea".truelength()