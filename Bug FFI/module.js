import KuwazyEngine from "./kuwazy_engine/wrapper/javascript/kuwazy_engine.mjs";

export default class GameServer{
    constructor (){
        const vecA = new KuwazyEngine.Vector3(1, 2, 3); // That works!
        console.log(Date.now(), vecA.x, vecA.y, vecA.z);

        setInterval(() => {
            const vecB = new KuwazyEngine.Vector3(1, 2, 3); // Bug ? (exited with code 11 (SIGSEGV))
            console.log(Date.now(), vecB.x, vecB.y, vecB.z);
        }, 1000);
    }
}
