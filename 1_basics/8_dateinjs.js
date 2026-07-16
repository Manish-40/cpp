// Dates

let mydate=new Date();
console.log(mydate.toString());
console.log(mydate.toDateString());
console.log(mydate.toLocaleString());
console.log(typeof mydate);



let mycreateddate=new Date(2023,0,23); // YYYY,MM,DD Month js ma 0 thi start thay che output tostring  Mon Jan 23 2023
let mycustomdate=new Date(2023,0,23,5,3); // YYYY,MM,DD,HOURS,MINUTES output tolocalstring 1/23/2023, 5:03:00 AM
console.log(mycreateddate.toDateString());
console.log(mycustomdate.toLocaleString());

let date=new Date("2023-01-14") //YYYY-MM-DD
let indiadate=new Date("01-14-2023") // India ma MM-DD-YYYY use thay che
console.log(date.toLocaleString());
console.log(indiadate.toLocaleString());


let myTimeStamp=Date.now();
console.log(myTimeStamp);
console.log(indiadate.getTime());
console.log(Math.floor(Date.now()/1000)); //seconds

let newDate=new Date()
console.log(newDate.getMonth()+1); // 0 this start thase +1 thi 1 thi start thase month
console.log(newDate.getDay()); // mon-1, tue-2 wed-3 thur-4 fri-5 sat-6 sun-7

// `${newDate.getDay()} and the time`

newDate.toLocaleString('default',{
    weekday:"long",
})