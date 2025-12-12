import { PrismaClient } from '@prisma/client';

const prisma = new PrismaClient();

async function creteURL(longUrl: string, ownerId?: bigint | null, expiresAt?: Date | null) {
    const created = await prisma.url.create({
        data: {
            longUrl,
            shortUrl: "", // placeholder
            ownerId: ownerId ?? undefined,
            expiresAt: expiresAt ?? undefined,
        },
        select: { id: true },
    });

    const code = "123#";
    const update = await prisma.url.update({
        where: { id: created.id },
        data: { shortUrl: code },
    });

    return update;
}

async function main(){
    const result = await creteURL("https://www.example.com/very/long/url", BigInt(1), null);
    console.log(result);        
}

main()
  .catch((e) => {
    console.error(e);
    process.exit(1);
  })
  .finally(async () => {
    await prisma.$disconnect();
  });   