const mynums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

let newnums = mynums.map((num) => num + 10)

console.log(newnums);

newnums = mynums.map((num) => {
    return num + 10
})

console.log(newnums);


// chaining

let nnum = mynums
    .map((num) => num * 10)
    .map((num)=>num+1)
    .filter((num)=>num>=40) // filter returns only true statement 

console.log(nnum);
