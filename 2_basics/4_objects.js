const tinderuser = new Object(); // sinfleton object 
const tinder = {} // non sinfleton object

tinderuser.id = "123abc"
tinderuser.name = "Sammy"
tinderuser.isLoggedIn = false;

console.log(tinderuser);

const regularuser = {
    email: "some@gmail.com",
    fullname: {
        userfullname: {
            firstname: "hitesh",
            lastname: "choudhary"
        }
    }
}

console.log(regularuser.fullname.userfullname.firstname);

const obj1 = { 1: "a", 2: "b" }
const obj2 = { 3: "a", 4: "d" }
// const obj3={obj1,obj2} // object na andar object banavse
//const obj3=Object.assign({},obj1,obj2) // {}-taget obj1,obj2 - source
// {} aa na aapyu to obj1 ni andar badhi value jati rese

const obj3 = { ...obj1, ...obj2 }; //spread
console.log(obj3);

const users = [
    {
        id: 1,
        email: "h@gmail.com"
    },
    {
        id: 2,
        email: "h@gmail.com"
    }
]

// users.map
console.log(users[1].email)

console.log(tinderuser);

console.log(Object.keys(tinderuser)); // aama loop lagavi ne acces kari sakiye 
console.log(Object.values(tinderuser));
console.log(Object.entries(tinderuser)); //key value ne array ma convert kari dese
console.log(tinderuser.hasOwnProperty('isLogged'));




const course = {
    courseName: "jsinhindi",
    price: 999,
    courseTeacher: "hc",
}
// course.courseTeacher

const { courseTeacher: instructor, courseName } = course;
// console.log(courseTeacher);
console.log(courseName);
// console.table({courseTeacher,courseName});
console.log(instructor);

// React function
// const navbar=(props.company)=>{
// }
// navbar(company="hitesh")

const navbar = ({ company }) => {
}
navbar(company = "hitesh")
// json

// {
//     "name":"hitesh",
//     "coursename":"jsinhindi",
// }

[
    {},
    {}
]