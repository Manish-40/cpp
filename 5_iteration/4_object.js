const myobj={
    js:"javascript",
    cpp:"c++",
    rb:"ruby",
    swift:"swift by apple"
}
for (const key in myobj) {
    console.log(`${key} shortcut is for ${myobj[key]}`);
}

const myarr=["js","ruby","cpp","java","py"]

for (const key in myarr) {
    console.log(myarr[key]);
    
}