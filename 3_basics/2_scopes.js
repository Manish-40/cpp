// var c=300;
// global scope

let a=300;
if (true) {
// local scope
// block scope
    let a = 10;
    const b = 20;
    console.log("Inner: ", a);
    
}

console.log("Outer: ", a);
// console.log(b);
// console.log(c);


function one(){
    const usernmame="hitesh";
    function two(){
        const website="youtube";
        console.log(usernmame);
    }
    // console.log(website); //error
    two();
}
one();


if(true)
{
    const usernmame="hitesh";
    if(usernmame==="hitesh")
    {
        const website=" youtube";
        console.log(usernmame+website);
        
    }
    // console.log(website);
    
}
// console.log(usernmame);


// Interesting

console.log(addone(5));
function addone(num){
    return num +1;
}

addtwo(5) // error cannot access addtwo before initialization
const addtwo=function(num){
return num+2;
}
addtwo(5)

