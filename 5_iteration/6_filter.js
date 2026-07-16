const mynums=[1,2,3,4,5,6,7,8,9,10]

const newnums=mynums.filter((num)=>num>4)
console.log(newnums);

const newnums2=mynums.filter((num)=>(num>4))
console.log(newnums2);


const newnums1=mynums.filter((num)=>{
    return num>4
})
console.log(newnums1);

// const arr=[]
// arr.forEach((num)=>{
// if(num>4)
// {
//     arr.push(num)
// }
// });
// console.log(arr);

const books=[
    {
        title:'book one',
        genre:'fiction',
        publish:1981,
        edition:2004
    },
    {
        title:'book two',
        genre:'non-fiction',
        publish:1992,
        edition:2008
    },
]


let userbooks=books.filter((bk)=>bk.genre==='fiction')
userbooks=books.filter((bk)=>{
    return bk.publish>=1970 && bk.genre==='non-fiction'
})
console.log("userbooks",userbooks);
