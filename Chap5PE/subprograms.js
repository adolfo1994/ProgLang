
function parent () {
    var parent_var = 0;
    function level1(){
        var l1_var = 1;
        console.log("parent_var from L1:" + parent_var);
        function level2(){
            var l2_var = 2;
            console.log("parent_var from L2: " + parent_var);
            console.log("l1_var from L2: " + l1_var);
            function level3(){
                console.log("parent_var from L3:" + parent_var);
                console.log("l1_var from L3:" + l1_var); 
                console.log("l2_var from L3:" + l2_var);
            }
            level3();
        }
        level2();
    }
    level1();
}
parent();
//Output:
/*

parent_var from L1:0
parent_var from L2: 0
l1_var from L2: 1
parent_var from L3:0
l1_var from L3:1
l2_var from L3:2



*/