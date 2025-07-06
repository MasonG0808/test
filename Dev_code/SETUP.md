# 项目设置说明

## 环境要求

- Python 3.8+
- FastAPI
- SQLAlchemy
- 其他依赖见 `requirements.txt`

## 安装依赖

```bash
pip install -r requirements.txt
```

## 运行项目

```bash
# 启动开发服务器
uvicorn app.main:app --reload --host 0.0.0.0 --port 8000
```

## 主要修改

### 1. 登录功能优化

- **问题**：之前登录需要同时提供用户名、邮箱和密码，造成冗余
- **解决方案**：现在支持用户名+密码或邮箱+密码两种登录方式
- **修改文件**：
  - `app/schemas.py` - 新增 `UserLogin` 模型
  - `app/crud.py` - 新增 `authenticate_user_by_username_or_email` 函数
  - `app/routers/users.py` - 修改登录接口
  - `Readme.md` - 更新API文档

### 2. 移除团队字段

- **问题**：`team_name` 字段不再需要
- **解决方案**：完全移除 `team_name` 相关代码
- **修改文件**：
  - `app/models.py` - 移除 `team_name` 字段
  - `app/schemas.py` - 移除 `team_name` 相关模型
  - `app/crud.py` - 移除 `team_name` 相关代码
  - `Readme.md` - 更新API文档

### 3. 新增文件

#### requirements.txt
项目依赖文件，包含所有必需的Python包。

#### openai.json
API接口文档，用于AI生成前端代码。包含：
- 完整的API接口描述
- 请求/响应格式
- 错误处理
- 使用示例

#### generate_openai_json.py
自动生成 `openai.json` 的Python脚本。

#### pre-push.bat
Windows批处理文件，用于在Git push前自动更新 `openai.json`。

## 使用说明

### 自动生成API文档

1. **手动生成**：
   ```bash
   python generate_openai_json.py
   ```

2. **自动生成**（推荐）：
   - 在Windows上，每次 `git push` 时会自动运行 `pre-push.bat`
   - 脚本会自动生成最新的 `openai.json` 并提交到仓库

### 前端开发

使用 `openai.json` 文件可以：
1. 直接提供给AI助手生成前端代码
2. 作为API接口的完整参考文档
3. 自动生成TypeScript类型定义
4. 生成API客户端代码

## API变更说明

### 登录接口变更

**之前**：
```json
{
  "username": "string",
  "email": "string", 
  "password": "string"
}
```

**现在**：
```json
{
  "username_or_email": "string",
  "password": "string"
}
```

### 用户模型变更

**移除字段**：
- `team_name` - 队伍名称

**保留字段**：
- `id` - 用户ID
- `username` - 用户名
- `email` - 邮箱
- `is_active` - 是否激活
- `is_verified` - 是否验证
- `created_time` - 创建时间
- `roles` - 用户角色

## 注意事项

1. 数据库迁移：如果已有数据，需要手动删除 `team_name` 字段
2. 前端适配：需要更新前端代码以适配新的登录接口
3. API文档：`openai.json` 会在每次push时自动更新 