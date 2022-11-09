a1 = document.getElementById("m1");
a2 = document.getElementById("m2");
a3 = document.getElementById("m3");

let flag = true;
let timer;
function Mover(elem) {
    if (!flag) {
        flag = true;
        clearTimeout(timer);
    }
    if (a1.style.display == "block") {
        a1.style.display = "none";
    }
    if (a2.style.display == "block") {
        a2.style.display = "none";
    }
    if (a3.style.display == "block") {
        a3.style.display = "none";
    }

    elem.style.display = "block";
}
function Mout(elem) {
    if (flag) {
        flag = false;
        m = elem;
        timer = setTimeout("m.style.display = 'none'", 2000);
    }
}
function Aover(elem) {
    var i=Math.floor(Math.random()*8);
    if (i==0)
        elem.style.background="black";
    if (i==1)
    elem.style.background="blue";
    if (i==2)
    elem.style.background="red";
    if (i==3)
    elem.style.color="orange";
    if (i==4)
    elem.style.color="red";
    if (i==5)
    elem.style.color="green";
    if (i==6)
    elem.style.fontStyle = "italic";  
    if (i==7)
    elem.style.fontWeight = "bold";  
}

function Aout(elem) {
    elem.style.background="none";
    elem.style.color="purple";
    elem.style.fontStyle = "normal"; 
    elem.style.fontWeight = "normal";  
}

