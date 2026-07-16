// Number
const score=400
console.log(score);

const balance=new Number(100)
console.log(balance);

console.log(balance.toString().length);
console.log(balance.toFixed(1));  // output 100.0 

const othernumber=123.89665
console.log(othernumber.toPrecision(4));

// precision(23.89665)(3)=>23.9
// precision(123.89665)(3)=>124

const hundreds=1000000
console.log(hundreds.toLocaleString()); // output 1000000=>1,000,000 us standard 
console.log(hundreds.toLocaleString('en-IN')); // output 1000000=> 10,00,000


// Maths

console.log(Math);
console.log(Math.abs(-4));
console.log(Math.round(4.6));
console.log(Math.ceil(4.2)); // ceil hamesha upper top ni value leseceil aetle 4 thi jara bhi upper . ma che to hu 5 kari dais jemke 4.2=>5 
console.log(Math.floor(4.9)); // floor hamesha niche ni value lese
console.log(Math.sqrt(25));
console.log(Math.pow(2,2));
console.log(Math.min(4,3,6,8));
console.log(Math.max(4,3,6,8));


console.log(Math.random()); // math.random hamesha 0 ane 1 ni vache aavse 0 bhi hoy skae 1 bhi hoy sake
console.log(Math.random()*10 + 1);
console.log((Math.random()*10) + 1);
console.log(Math.floor((Math.random()*10)) + 1);

const min=10;
const max=20;


console.log(Math.floor(Math.random()*(max-min+1))+min);
// max-min +1  0 na aave aetle +1
// (max-min+1) +min min na range thi chalu thay max tak aena mate
// Math.floor kemke nani value re upper jem  

