function setCharAt(str,index,chr) {
	if(index > str.length-1) return str;
	return str.substr(0,index) + chr + str.substr(index+1);
}

const fs = require('fs');

try {

    const data = 
    // fs.readFileSync('input.txt', 'UTF-8');
    fs.readFileSync('/dev/stdin', 'UTF-8'); // NO URI / LINUX funciona assim

    const lines = data.split(/\r?\n/);

    let exp,f,soZeros,v2,s,str,f2,resp,fNegativo;

    while(lines.length > 1){ // eof

        exp = lines.shift();
        f = exp.length > 0 ? true : false;
        soZeros = true;
        str = '';
        fNegativo = false;

        if(!f){
            console.log("error");
        }else{
        
            if(f && exp[0]==="-"){ // numero negativo
                console.log("error");
            }else{

                if(f){

                    for(let i=0;i<exp.length && soZeros;i++){ // so zeros

                        if(exp[i]!=="0"){
                            soZeros = false;
                        }
                    }

                    if(soZeros){
                        console.log("0");
                    }else{

                        v2 = exp.trim();
                        if(v2.length===0){ // so espaços!
                            console.log("error");
                        }else{

                            s = exp;
                            s = s.replace(/^0+/,''); // retira 0's a esquerda

                            for(let j=0;j<s.length;j++){ // trato os o/O e l's

                                if(s[j]==='-'){
                                    fNegativo = true;
                                }

                                if(s[j]!==' ' && s[j]!==','){

                                    if(s[j]==='o' || s[j]==='O'){
                                        s = setCharAt(s,j,'0');
                                    }
        
                                    if(s[j]==='l'){
                                        s = setCharAt(s,j,'1');
                                    }
                                    str += s[j];
                                }
                            }

                            if(str.length===0){ // por exemplo = ",,, ,"
                                console.log("error");
                            }else{

                                f2 = isNaN(str); // tem char tipo & ou * ou @ etc

                                if(!f2 && !fNegativo){

                                    resp = parseInt(str);

                                    if(resp > 2147483647){ // valor máximo permitido!
                                        console.log("error");
                                    }else{
                                        console.log(resp);
                                    }
                                }else{
                                    console.log("error");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
        
} catch (err) {
    console.error(err);
}
