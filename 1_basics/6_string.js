const name="hitesh"
const repocount=50

// console.log(name+repocount+" Value");

console.log(`Hello my name is ${name} and my repo count is ${repocount}`);

const gameName=new String('hitesh-hc');

console.log(gameName[0]);

console.log(gameName.__proto__);

console.log(gameName.length);
console.log(gameName.toLocaleUpperCase());
console.log(gameName.charAt(2));
console.log(gameName.indexOf('t'));

const newstring=gameName.substring(0,4)
console.log(newstring);

const anotherstring=gameName.slice(-8,4)
console.log(anotherstring);

const newstring1="   hitesh    "
console.log(newstring1);
console.log(newstring1.trim());

const url="https://hitesh.com/hitesh%20choudhary"
console.log(url.replace('%20','-'));

console.log(url.includes('hitesh'));
console.log(url.includes('sundar'));

console.log(gameName.split('-'));