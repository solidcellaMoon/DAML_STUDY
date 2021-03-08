var userEmail = prompt("이메일 주소를 입력하세요","");
var arrURL = [".co.kr",".com",".net",".or.kr",".go.kr"];

var check1 = false; // @ 입력했는가?
var check2 = false; // arrURL에 속하는 도메인인가?

// @의 인덱스가 정상적으로 존재하면 
if(userEmail.indexOf("@") > 0) {check1 = true;}

for(var i=0; i<arrURL.length; i++){
    if(userEmail.indexOf(arrURL[i]) > 0){
        check2 = true;
    }
}

if(check1 && check2){
    document.write("your Email is: ",userEmail);
} else {
    alert("wrong Email!!");
}