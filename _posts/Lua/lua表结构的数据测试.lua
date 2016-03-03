--wanglin 12/29 
--表结构的优化 ：http://www.cnblogs.com/gdev/archive/2012/08/22/lua-performance-tips-5.html
--涉及到的内容：
--1、表结构的优化
--2、元表中__index，__pairs，__newindex 等的修改
--3、rawget：跟进字符串在表中取对应值
--4、next：在pairs遍历中获取下一项的数据


--first
local t_card_f = {
	{code = 1000, name = "堕落天使"},
	{code = 1001, name = "零度之手"},
}

--second
local t_card_s = {
	{1000,"堕落天使"},
	{1001,"零度之手"},
}

--third
local t_card_t = {
	code = {1000,1001},
	name = {"堕落天使","零度之手"},
}

--four
local t_card_four = {
	[10100001] = {10100001,"堕落天使","路西法"},--(code,name,byname)
	[10100002] = {10100002,"零度之手","特里斯坦"},
}


local keys = {code = 1, name = 2, byname = 3 }
local reverseKeys = {"code", "name", "byname", }
local mt = {
	--访问不存在字段时，调用
	__index = function (t,k)
		--根据传进来的name，code在keys表中找对应的value，用该value作为index索引去获取对应位置的数据
		local newKey = rawget(keys,k)
		print("访问到不存在变量，创进来的key是：",k,newKey)
		return t[newKey]
	end,
	--更新的时候调用，即对配置表写入时触发
	__newindex = function (t,k,v)
		print("你要修改表？不给")
	end,
	__ipairs = function()
       error("ipairs iter is not allow, use pairs instead")
    end,

}

--设置元表
setmetatable(t_card_four,mt)

local code = 10100001
local inMt = {
	--访问不存在字段时，调用
	__index = function (t,k)
		local newKey = rawget(keys,k)
		return t[newKey]
	end,
	--更新的时候调用，即对配置表写入时触发
	__newindex = function (t,k,v)
		print("你要修改子表？不给")
	end,
	--遍历子表时被触发
	__pairs = function (t)
		local k2
		return function ()
			local k,v
			--k2 为空时取第一项，取第一项后k2则为第一项的key再传入可以取第二项的数据
			k2,v = next(t , k2)
			if v then
				k = reverseKeys[k2]
			end
			--返回设置好的新key和对应的值
			return k ,v
		end
	end,
}

--遍历子表，并设置子表的元表
for k in pairs(t_card_four) do
	--对子表设置元表
	setmetatable(t_card_four[k],inMt)
end

-----Exp1
print("------- Exp 1 -------")
--遍历子表的数据
local xiaobiao = t_card_four[code]
for k in pairs(xiaobiao) do
--	print(k," ： ",xiaobiao[k])
end

-----Exp2
print("------- Exp 2 -------")
--遍历大表
for k in pairs(t_card_four) do
--	print(k," ： ",t_card_four[k])
end

-----Exp3

print("------- Exp 3 -------")
code = 10100001 --{10100001,"堕落天使"}
--读取数据的形式
--print(t_card_four[code]) --可以访问父表数据的形式
--print(t_card_four[code].name) --可以访问的子表数据形式（原因是对子表设置了元表）
--print(t_card_four.code) -- key无法用.的形式访问

--修改数据的形式
--t_card_four[code]={}--修改父表的某一项数据，没警告
--t_card_four[112]={}--添加父表的一项数据，警告提示
--t_card_four[code].name={}--修改子表的数据，警告提示








