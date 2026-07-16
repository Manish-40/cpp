const coding=["js","ruby","java","python","cpp"]


coding.forEach( function (val){ // callbackfn callback function che to function nu name nahi aave 
console.log(val);
})

coding.forEach((val)=>{
console.log(val);
})

function printMe(item){
console.log(item);
}

coding.forEach(printMe)

coding.forEach((item,index,arr)=>{
    console.log(item,index,arr);
})

const mycoding=[
    {
        languagename:"javascript",
        languagefile:"js"
    },
    {
        languagename:"java",
        languagefile:"java"
    },
    {
        languagename:"c++",
        languagefile:"cpp"
    },
]

mycoding.forEach((item)=>{
console.log(item.languagename);
console.log(item.languagefile);
})