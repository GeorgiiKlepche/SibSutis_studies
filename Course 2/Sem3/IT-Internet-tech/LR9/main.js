let username;

function setCookie(visits){
	let expire = new Date();
	let today = new Date();
	expire.setDate(expire.getDate + 30);
	document.cookie = "user=" + username + "; expires=" +
	encodeURIComponent(expire.toUTCString());
	document.cookie = "visits=" + visits + "; expires=" +
	encodeURIComponent(expire.toUTCString());
	document.cookie = "lastVisit=" + encodeURIComponent(today.toUTCString()) +
	"; expires=" + encodeURIComponent(expire.toUTCString());
}

function getCookie(Name){   
	let search = Name + "=";
	if(document.cookie.length > 0){
		offset = document.cookie.indexOf(search);
		if(offset != -1){
			offset += search.length;
			end = document.cookie.indexOf("; ", offset);
			if(end == -1)
				end = document.cookie.length;
			return decodeURIComponent(document.cookie.substring(offset, end));
		}
	}
}

function deleteAllCookies(){
    let cookies = document.cookie.split("; ");
    for(let i = 0; i < cookies.length; i++){
        let cookie = cookies[i];
        let eqPos = cookie.indexOf("=");
        let name = eqPos > -1 ? cookie.substring(0, eqPos) : cookie;
        document.cookie = name + "=; expires=Thu, 01 Jan 1970 00:00:00 GMT";
    }
}

function getForm(event){
    event.preventDefault();
	username = document.forms["form"].elements["in"].value;
	document.forms["form"].elements["in"].value = "";
	if(document.cookie)
		setCookie(getCookie("visits"));
	else
		setCookie(1);
	document.getElementById('count1').style.visibility = "visible";
	document.getElementById('count0').style.visibility = "hidden";
	document.getElementById('name').innerHTML = username + '!';
	document.getElementById('count').innerHTML = Number(getCookie("visits"));
	document.getElementById('date').innerHTML = time();
}

function clear(event){
	event.preventDefault();
	deleteAllCookies();
	document.getElementById('count1').style.visibility = "hidden";
	document.getElementById('count0').style.visibility = "visible";
}

function time(){
	let lastVisit = new Date(getCookie("lastVisit"));
	let lastvisit = lastVisit[Symbol.toPrimitive]('number');
	let Now = new Date();
	let now = Now[Symbol.toPrimitive]('number');
	let difference = Math.floor((now - lastvisit)/1000);
	let days = Math.floor(difference/60/60/24);
	difference = difference - days*60*60*24;
	let hours = Math.floor(difference/60/60);
	difference = difference - hours*60*60;
	let minutes = Math.floor(difference/60);
	difference = difference - minutes*60;
	let seconds = difference;
	let string = "";
	if(days > 0){
		string = days + " дней, " + hours + " часов, " + minutes + " минут, " +
				 seconds + " секунд назад";
		return string;
	}
	else if(hours > 0){
		string = hours + " часов, " + minutes + " минут, " + seconds + " секунд назад";
		return string;
	}
	else if(minutes > 0){
		string = minutes + " минут, " + seconds + " секунд назад";
		return string;
	}
	else if(seconds> 0){
		string = seconds + " секунд назад";
		return string;
	}
	else{
		string = "Только что";
		return string;
	}
}

document.addEventListener('DOMContentLoaded', () => {
	document.getElementById('b1').addEventListener('click', getForm);
	document.getElementById('b2').addEventListener('click', clear);
	if(document.cookie != ""){
		username = getCookie("user");
		document.getElementById('count1').style.visibility = "visible";
		document.getElementById('count0').style.visibility = "hidden";
		document.getElementById('name').innerHTML = username + '!';
		document.getElementById('count').innerHTML = Number(getCookie("visits"))+1;
		document.getElementById('date').innerHTML = time();
		setCookie(Number(getCookie("visits"))+1);
	}
});