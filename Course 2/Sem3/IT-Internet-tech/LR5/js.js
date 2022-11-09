image = document.getElementById("image")
image2 = document.getElementById("image2")
start = document.getElementById("start")
stop1 = document.getElementById("stop")
faster = document.getElementById("fast")
slow = document.getElementById("slow")
let timer;
let temp;
let i = 1;
let sec;

fast.disabled = true;
slow.disabled = true;


faster.onclick = function fast(){
    clearInterval(timer);
    sec/=2;
    timer = setInterval(tim, sec)
}

slow.onclick = function slower(){
    clearInterval(timer);
    sec*=2;
    timer = setInterval(tim, sec)
}

start.onclick = function pusk(){
    sec = 200;
    timer = setInterval(tim, sec)
    start.disabled = true;
    fast.disabled = false;
    slow.disabled = false;
}

stop1.onclick = function pause(){
    clearInterval(timer);
    start.disabled = false;
    fast.disabled = true;
    slow.disabled = true;
}

function tim(){
    imag = new Image();
    imag.src = "s"+i+".gif"
    image.src = imag.src;
    if (i==8){
        temp = image;
        image = image2;
        image2 = temp;
    }
    if (i==12){
        i = 1;
    }
    i++;
}