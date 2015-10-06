
def parent():
    parent_var = 0
    def level1():
        l1_var = 1
        print "parent_var from L1: %d" % parent_var 
        def level2():
            l2_var = 2
            print "parent_var from L2: %d" % parent_var 
            print "l1_var from L2: %d" % l1_var 

            def level3():
                print "parent_var from L3: %d" % parent_var 
                print "l1_var from L3: %d" % l1_var
                print "l2_var from L3: %d" % l2_var
            level3()
        level2()                 
    level1()
parent()

# Output
# parent_var from L1: 0
# parent_var from L2: 0
# l1_var from L2: 1
# parent_var from L3: 0
# l1_var from L3: 1
# l2_var from L3: 2
